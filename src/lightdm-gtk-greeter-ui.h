
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
  "<?xml version=\"1.0\" encoding=\"UTF-8\"?><interface><requires lib=\"gtk+\" version=\"3.4\"/><object class=\"GtkAccelGroup\" id=\"a11y_accelgroup\"/><object class=\"GtkAccelGroup\" id=\"power_accelgroup\"/><object class=\"GtkWindow\" id=\"panel_window\"><property name=\"name\">panel_window</property><property name=\"can_focus\">False</property><property name=\"decorated\">False</property><accel-groups><group name=\"a11y_accelgroup\"/><group name=\"power_accelgroup\"/></accel-groups><child><object class=\"GreeterMenuBar\" id=\"menubar\"><property name=\"name\">menubar</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"pack_direction\">rtl</property><signal name=\"key-press-event\" handler=\"menubar_key_press_cb\" swapped=\"no\"/><child><object class=\"GtkMenuItem\" id=\"power_menuitem\"><property name=\"name\">power_menuitem</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><child type=\"submenu\"><object class=\"GtkMenu\" id=\"power_menu\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"accel_group\">power_accelgroup</property><child><object class=\"GtkMenuItem\" id=\"suspend_menuitem\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label\" translatable=\"yes\">Suspend</property><signal name=\"activate\" handler=\"suspend_cb\" swapped=\"no\"/></object></child><child><object class=\"GtkMenuItem\" id=\"hibernate_menuitem\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label\" translatable=\"yes\">Hibernate</property><signal name=\"activate\" handler=\"hibernate_cb\" swapped=\"no\"/></object></child><child><object class=\"GtkMenuItem\" id=\"restart_menuitem\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label\" translatable=\"yes\">Restart...</property><signal name=\"activate\" handler=\"restart_cb\" swapped=\"no\"/></object></child><child><object class=\"GtkMenuItem\" id=\"shutdown_menuitem\"><property name=\"use_action_appearance\">False</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"accel_path\">&lt;Login&gt;/power/shutdown</property><property name=\"label\" translatable=\"yes\">Shut Down...</property><signal name=\"activate\" handler=\"shutdown_cb\" swapped=\"no\"/></object></child></object></child></object></child><child><object class=\"GtkMenuItem\" id=\"a11y_menuitem\"><property name=\"name\">a11y_menuitem</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><child type=\"submenu\"><object class=\"GtkMenu\" id=\"a11y_menu\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"accel_group\">a11y_accelgroup</property><child><object class=\"GtkCheckMenuItem\" id=\"large_font_menuitem\"><property name=\"use_action_appearance\">False</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"accel_path\">&lt;Login&gt;/a11y/font</property><property name=\"label\" translatable=\"yes\">Large Font</property><signal name=\"toggled\" handler=\"a11y_font_cb\" swapped=\"no\"/></object></child><child><object class=\"GtkCheckMenuItem\" id=\"high_contrast_menuitem\"><property name=\"use_action_appearance\">False</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"accel_path\">&lt;Login&gt;/a11y/contrast</property><property name=\"label\" translatable=\"yes\">High Contrast</property><signal name=\"toggled\" handler=\"a11y_contrast_cb\" swapped=\"no\"/></object></child><child><object class=\"GtkCheckMenuItem\" id=\"keyboard_menuitem\"><property name=\"use_action_appearance\">False</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"accel_path\">&lt;Login&gt;/a11y/keyboard</property><property name=\"label\" translatable=\"yes\">On Screen Keyboard</property><property name=\"use_underline\">True</property><signal name=\"toggled\" handler=\"a11y_keyboard_cb\" swapped=\"no\"/></object></child><child><object class=\"GtkCheckMenuItem\" id=\"reader_menuitem\"><property name=\"use_action_appearance\">False</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"accel_path\">&lt;Login&gt;/a11y/reader</property><property name=\"label\" translatable=\"yes\">Screen Reader</property><property name=\"use_underline\">True</property><signal name=\"toggled\" handler=\"a11y_reader_cb\" swapped=\"no\"/></object></child></object></child></object></child><child><object class=\"GtkMenuItem\" id=\"language_menuitem\"><property name=\"name\">language_menuitem</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"label\">[language_code]</property><child type=\"submenu\"><object class=\"GtkMenu\" id=\"language_menu\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property></object></child></object></child><child><object class=\"GtkMenuItem\" id=\"session_menuitem\"><property name=\"name\">session_menuitem</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><child type=\"submenu\"><object class=\"GtkMenu\" id=\"session_menu\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property></object></child></object></child><child><object class=\"GtkMenuItem\" id=\"layout_menuitem\"><property name=\"name\">layout_menuitem</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"label\">[layout]</property><child type=\"submenu\"><object class=\"GtkMenu\" id=\"layout_menu\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property></object></child></object></child><child><object class=\"GtkSeparatorMenuItem\" id=\"clock_menuitem\"><property name=\"name\">clock_menuitem</property><property name=\"can_focus\">False</property></object></child><child><object class=\"GtkSeparatorMenuItem\" id=\"host_menuitem\"><property name=\"name\">host_menuitem</property><property name=\"can_focus\">False</property></object></child></object></child><style><class name=\"lightdm-gtk-greeter\"/><class name=\"menubar\"/></style></object><object class=\"GtkListStore\" id=\"user_liststore\"><columns><column type=\"gchararray\"/><column type=\"gchararray\"/><column type=\"gint\"/></columns></object><object class=\"GtkWindow\" id=\"login_window\"><property name=\"name\">login_window</property><property name=\"can_focus\">False</property><property name=\"resizable\">False</property><property name=\"decorated\">False</property><accel-groups><group name=\"a11y_accelgroup\"/><group name=\"power_accelgroup\"/></accel-groups><signal name=\"key-press-event\" handler=\"login_window_key_press_cb\" swapped=\"no\"/><child><object class=\"GtkBox\" id=\"box1\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"orientation\">vertical</property><child><object class=\"GtkFrame\" id=\"content_frame\"><property name=\"name\">content_frame</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label_xalign\">0</property><property name=\"shadow_type\">none</property><child><object class=\"GtkGrid\" id=\"grid1\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"margin_left\">24</property><property name=\"margin_right\">24</property><property name=\"margin_top\">24</property><property name=\"row_spacing\">6</property><property name=\"column_spacing\">18</property><child><object class=\"GtkFrame\" id=\"user_image_border\"><property name=\"name\">user_image_border</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"halign\">center</property><property name=\"valign\">center</property><property name=\"label_xalign\">0</property><property name=\"shadow_type\">none</property><child><object class=\"GtkImage\" id=\"user_image\"><property name=\"name\">user_image</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"pixel_size\">80</property><property name=\"icon_name\">avatar-default</property></object></child></object><packing><property name=\"left_attach\">1</property><property name=\"top_attach\">0</property><property name=\"width\">1</property><property name=\"height\">3</property></packing></child><child><object class=\"GtkEntry\" id=\"password_entry\"><property name=\"name\">prompt_entry</property><property name=\"width_request\">200</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"margin_bottom\">12</property><property name=\"hexpand\">True</property><property name=\"visibility\">False</property><property name=\"invisible_char\">\342\200\242</property><property name=\"primary_icon_activatable\">False</property><property name=\"secondary_icon_activatable\">False</property><property name=\"placeholder_text\" translatable=\"yes\">Enter your password</property><signal name=\"activate\" handler=\"login_cb\" swapped=\"no\"/><signal name=\"key-press-event\" handler=\"password_key_press_cb\" swapped=\"no\"/></object><packing><property name=\"left_attach\">0</property><property name=\"top_attach\">0</property><property name=\"width\">1</property><property name=\"height\">3</property></packing></child></object></child><child type=\"label_item\"><placeholder/></child></object><packing><property name=\"expand\">True</property><property name=\"fill\">True</property><property name=\"position\">0</property></packing></child><child><object class=\"GtkInfoBar\" id=\"greeter_infobar\"><property name=\"name\">greeter_infobar</property><property name=\"app_paintable\">True</property><property name=\"can_focus\">False</property><child internal-child=\"action_area\"><object class=\"GtkButtonBox\" id=\"infobar-action_area1\"><property name=\"can_focus\">False</property><property name=\"layout_style\">end</property><child><placeholder/></child></object><packing><property name=\"expand\">False</property><property name=\"fill\">False</property><property name=\"position\">0</property></packing></child><child internal-child=\"content_area\"><object class=\"GtkBox\" id=\"infobar-content_area1\"><property name=\"can_focus\">False</property><child><object class=\"GtkLabel\" id=\"message_label\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label\" comments=\"This is a placeholder string and will be replaced with a message from PAM\">[message]</property></object><packing><property name=\"expand\">True</property><property name=\"fill\">True</property><property name=\"position\">0</property></packing></child></object><packing><property name=\"expand\">False</property><property name=\"fill\">False</property><property name=\"position\">0</property></packing></child></object><packing><property name=\"expand\">False</property><property name=\"fill\">True</property><property name=\"position\">1</property></packing></child><child><object class=\"GtkFrame\" id=\"buttonbox_frame\"><property name=\"name\">buttonbox_frame</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label_xalign\">0</property><property name=\"shadow_type\">none</property><child><object class=\"GtkBox\" id=\"box2\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"margin_left\">24</property><property name=\"margin_right\">24</property><property name=\"margin_bottom\">24</property><child><object class=\"GtkButton\" id=\"login_button\"><property name=\"label\" translatable=\"yes\">Log In</property><property name=\"name\">login_button</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><signal name=\"clicked\" handler=\"login_cb\" swapped=\"no\"/></object><packing><property name=\"expand\">False</property><property name=\"fill\">True</property><property name=\"pack_type\">end</property><property name=\"position\">0</property></packing></child></object></child><child type=\"label_item\"><placeholder/></child></object><packing><property name=\"expand\">False</property><property name=\"fill\">True</property><property name=\"position\">2</property></packing></child></object></child><style><class name=\"lightdm-gtk-greeter\"/></style></object></interface>"
};

static const unsigned lightdm_gtk_greeter_ui_length = 12243u;

