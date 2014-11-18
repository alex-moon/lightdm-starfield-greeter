#!/usr/bin/python
# -*- coding: UTF-8 -*-
input_filename = 'lightdm-gtk-greeter.glade'
output_filename = 'lightdm-gtk-greeter-ui.h'

header = """
/* Alex Moon, ladies and gentlemen, boy howdy */
#ifdef __SUNPRO_C
#pragma align 4 (lightdm_gtk_greeter_ui)
#endif
#ifdef __GNUC__
static const char lightdm_gtk_greeter_ui[] __attribute__ ((__aligned__ (4))) =
#else
static const char lightdm_gtk_greeter_ui[] =
#endif
{
"""

footer = """
};

static const unsigned lightdm_gtk_greeter_ui_length = %du;

"""

CHUNK_LENGTH = 76

output = ''
output_len = 0
with open(input_filename, 'r') as input_file:
    inside_comment = inside_tag = inside_property = False
    for line in input_file:
        for i, char in enumerate(line):
            if inside_comment:
                if char == '>' and line[i - 2:i + 1] == '-->':
                    inside_comment = False
                    continue
            else:
                if char == '<':
                    if line[i:i + 4] == '<!--':
                        inside_comment = True
                        continue
                    elif not inside_property and line[i:i + 9] == '<property':
                        inside_property = True
                    elif not inside_property:
                        inside_tag = True
                elif inside_tag and char == '>':
                    inside_tag = False
                elif inside_property and line[i - 10:i + 1] == '</property>':
                    inside_property = False

                if char in ['\t', '\n', '\r']:
                    char = ' '
                if not inside_tag and not inside_property and char == ' ':
                    continue
                if char == '"':
                    char = '\\"'
                if char == '\342':
                    char = '\\342'
                if char == '\200':
                    char = '\\200'
                if char == '\242':
                    char = '\\242'
                output += char
                output_len += 1

# splits escaped slashes nrrr
#     for chunk in [output[i:i + CHUNK_LENGTH] for i in range(0, len(output), CHUNK_LENGTH)]:
#         output_file.write('  "' + chunk + '"\n')

with open(output_filename, 'w') as output_file:
    output_file.write(header)
    output_file.write('  "' + output + '"')
    output_file.write(footer % output_len)
