#define STARS_MAX 5000

#define DRIFTING 42
#define CRUISING 69
#define ZOOMING 123
int move_mode = DRIFTING;

#define DRIFT_VELOCITY {-0.0003, 0.0, 0.0}
#define CRUISE_VELOCITY {0.0, 0.0, -0.01}
#define ZOOM_VELOCITY {0.0, 0.0, -0.02}

typedef struct {
    double x, y, z;
} Velocity;

Velocity drift_velocity = DRIFT_VELOCITY;
Velocity cruise_velocity = CRUISE_VELOCITY;
Velocity zoom_velocity = ZOOM_VELOCITY;

Velocity *move_velocity;

#define ACCELERATION 0.0001
#define EPSILON 0.0000001

static int double_eq(double a, double b) {
    return (
        (a <= b && a + EPSILON > b) ||
        (a >= b && a - EPSILON < b)
    );
}

static void accelerate_toward(Velocity *target) {
    if (!double_eq(move_velocity->x, target->x)) {
        if (move_velocity->x < target->x) move_velocity->x += ACCELERATION;
        else if (move_velocity->x > target->x) move_velocity->x -= ACCELERATION;
    }
    if (!double_eq(move_velocity->y, target->y)) {
        if (move_velocity->y < target->y) move_velocity->x += ACCELERATION;
        else if (move_velocity->y > target->y) move_velocity->y -= ACCELERATION;
    }
    if (!double_eq(move_velocity->z, target->z)) {
        if (move_velocity->z < target->z) move_velocity->z += ACCELERATION;
        else if (move_velocity->z > target->z) move_velocity->z -= ACCELERATION;
    }
}

static void accelerate(void);
void accelerate() {
    switch (move_mode) {
        case DRIFTING:
            accelerate_toward(&drift_velocity);
            break;
        case CRUISING:
            accelerate_toward(&cruise_velocity);
            break;
        case ZOOMING:
            accelerate_toward(&zoom_velocity);
            break;
    }
}

typedef struct {
    double x, y, z;
} Star;

static Star new_star(void);
static double star_px (Star *star);
static double star_py (Star *star);
static double star_x (Star *star, int width);
static double star_y (Star *star, int height);
static double star_brightness (Star *star);
static void populate_stars(void);
static void move_stars(void);
static void draw_star(cairo_t *cr, Star *star, int width, int height);
static void draw_stars(cairo_t *cr, int width, int height);
static void start_starfield(void);

static Star stars[STARS_MAX];
static int i; // horse shit


Star new_star(void) {
    Star star = {
        lolrand - 0.5,
        lolrand - 0.5,
        lolrand
    };
    return star;
}

double star_px (Star *star) {
    return star->x / star->z;
}

double star_py (Star *star) {
    return star->y / star->z;
}

double star_x (Star *star, int width) {
    return (star_px (star) + 0.5) * width;
}

double star_y (Star *star, int height) {
    return (star_py (star) + 0.5) * height;
}

double star_brightness (Star *star) {
    return (1.0 - star->z) * (1.0 - star->z);
}

void populate_stars(void) {
    for (i=0; i < STARS_MAX; i++) {
        stars[i] = new_star();
    }
}

void move_stars(void) {
    accelerate();
    for (i=0; i < STARS_MAX; i++) {
        stars[i].x += move_velocity->x;
        if (stars[i].x > 0.5 || stars[i].x < -0.5) stars[i].x = lolrand - 0.5;

        stars[i].y += move_velocity->y;
        if (stars[i].y > 0.5 || stars[i].y < -0.5) stars[i].y = lolrand - 0.5;

        stars[i].z += move_velocity->z;
        if (stars[i].z < 0.0) stars[i].z = 1.0;
        else if (stars[i].z > 1.0) stars[i].z = 0.0;
    }
}

// define your starfield colours here lol
#define STAR_RED 1.0
#define STAR_GREEN 1.0
#define STAR_BLUE 1.0
#define STARFIELD_BG_RGBA {0.0, 0.0, 0.0, 0.0}

static void draw_star(cairo_t *cr, Star *star, int width, int height) {
    if (
        star_px (star) > -0.5 &&
        star_px (star) < 0.5 &&
        star_py (star) > -0.5 &&
        star_py (star) < 0.5
    ) {
        cairo_set_source_rgba (cr, STAR_RED, STAR_GREEN, STAR_BLUE, star_brightness(star));
        cairo_move_to (cr, star_x (star, width), star_y (star, height));
        cairo_close_path (cr);
        cairo_stroke (cr);
    }
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

static void starfield_init(void);
void starfield_init(void) {
    move_velocity = malloc(sizeof(Velocity));
    populate_stars();
}