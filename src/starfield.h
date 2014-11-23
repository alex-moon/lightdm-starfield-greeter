#include <math.h>

#define STARS_MAX 5000
#define STAR_FIELD_WIDTH 3

#define DRIFTING 42
#define CRUISING 69
#define ZOOMING 123
int move_mode = DRIFTING;

#define DRIFT_SPEED -0.001
#define CRUISE_SPEED 0.005
#define ZOOM_SPEED 0.04

typedef struct {
    // 0 <= x,y,z <= 1 - absolute values used to calculate relative position on screen, brightness, etc.
    double x, y, z;
     // z == 1.0: star is touching camera, z == 0.0: star is "infinitely" far away
} Star;

static Star new_star(void);
static double star_x (Star *star, int width);
static double star_y (Star *star, int height);
static double star_brightness (Star *star);
static void populate_stars(void);
static void drift(Star *star);
static void cruise(Star *star);
static void zoom(Star *star);
static void move_stars(void);
static void draw_star(cairo_t *cr, Star *star, int width, int height);
static void draw_stars(cairo_t *cr, int width, int height);
static void start_starfield(void);

static Star stars[STARS_MAX];
static int i; // horse shit


Star new_star(void) {
    Star star = {
        (lolrand * 2 - lolrand) * STAR_FIELD_WIDTH,
        (lolrand * 2 - lolrand) * STAR_FIELD_WIDTH,
        lolrand
    };  // see lightdm-gtk-greeter.c for lolrand def
    return star;
}

double star_x (Star *star, int width) {
    return (star->x - 0.5) * width * star->z * star->z + width * 0.5;
}

double star_y (Star *star, int height) {
    return (star->y - 0.5) * height * star->z * star->z + height * 0.5;
}

double star_brightness (Star *star) {
    // return star->z;  // works just as well but a bit faint
    return 1.0 - (
        (1 - star->z) *
        (1 - star->z)
    );
}

void populate_stars(void) {
    for (i=0; i < STARS_MAX; i++) {
        stars[i] = new_star();
    }
}

void drift(Star *star) {
    star->x += DRIFT_SPEED;
    if (DRIFT_SPEED < 0.0 && star->x <= -STAR_FIELD_WIDTH) star->x += STAR_FIELD_WIDTH * 2;
    if (DRIFT_SPEED > 0.0 && star->x >= STAR_FIELD_WIDTH) star->x -= STAR_FIELD_WIDTH * 2;
}

void cruise(Star *star) {
    star->z += CRUISE_SPEED;
    if (star->z >= 1.0) {
        star->z -= 1.0;
    }
}

void zoom(Star *star) {
    star->z += ZOOM_SPEED;
    if (star->z >= 1.0) {
        star->z -= 1.0;
    }
}

void move_stars(void) {
    switch (move_mode) {
        case DRIFTING:
            for (i=0; i < STARS_MAX; i++) {
                drift(&stars[i]);
            }
            break;
        case CRUISING:
            for (i=0; i < STARS_MAX; i++) {
                cruise(&stars[i]);
            }
            break;
        case ZOOMING:
            for (i=0; i < STARS_MAX; i++) {
                zoom(&stars[i]);
            }
            break;
        default:
            break;
    }
}

// define your starfield colours here lol
#define STAR_RED 1.0
#define STAR_GREEN 1.0
#define STAR_BLUE 1.0
#define STARFIELD_BG_RGBA {0.0, 0.0, 0.0, 0.0}

static void draw_star(cairo_t *cr, Star *star, int width, int height) {
    cairo_set_source_rgba (cr, STAR_RED, STAR_GREEN, STAR_BLUE, star_brightness(star));
    cairo_move_to (cr, star_x (star, width), star_y (star, height));
    cairo_close_path (cr);
    cairo_stroke (cr);
}

void draw_stars(cairo_t *cr, int width, int height) {
    cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
    for (i=0; i < STARS_MAX; i++) {
        draw_star (cr, &stars[i], width, height);
    }
}

static void drift_starfield(void);
void drift_starfield(void) {
    move_mode = DRIFTING;
}

static void cruise_starfield(void);
void cruise_starfield(void) {
    move_mode = CRUISING;
}

static void zoom_starfield(void);
void zoom_starfield(void) {
    move_mode = ZOOMING;
}
