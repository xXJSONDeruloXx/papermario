/*
 * decomp/src/cam_main.c
 *
 * Minimal camera implementation required for the title-screen and sprite code.
 * The original N64 code contains many camera helpers; for now we only provide
 * the symbols that the current probe imports. All functions are deliberately
 * simple no-ops or return safe defaults – they exist solely so the linker can
 * resolve the symbols while we continue to integrate the full engine incrementally.
 */

#include "common.h"
#include "camera.h"

/* ----------------------------------------------------------------------
 * Camera viewport helper
 * ---------------------------------------------------------------------- */
void set_cam_viewport(s16 id, s16 x, s16 y, s16 w, s16 h) {
    // The real implementation would program the Fast3D viewport.
    // For now we simply store the values in a global (if needed later).
    (void)id; (void)x; (void)y; (void)w; (void)h;
}

/* ----------------------------------------------------------------------
 * Camera initialization – creates a default camera entry.
 * ---------------------------------------------------------------------- */
void init_default_camera(void) {
    // Initialise the first entry of gCameras[] (defined in cam_math.c)
    // with a sane identity view matrix and default parameters.
    Camera* cam = &gCameras[0];
    cam->pos.x = cam->pos.y = cam->pos.z = 0.0f;
    cam->lookAt.x = cam->lookAt.y = cam->lookAt.z = 0.0f;
    cam->curYaw = 0.0f;
    // Note: Some fields like 'up', 'curPitch', 'zoom' may not exist in the struct
    // in this version – we only set known fields to avoid compiler errors.
}

/* ----------------------------------------------------------------------
 * Camera update – called once per frame.
 * ---------------------------------------------------------------------- */
void update_cameras(void) {
    // The real game updates the view matrix each frame.
    // This stub does nothing; it merely satisfies the linker.
}

/* ----------------------------------------------------------------------
 * Misc camera helpers required by the title-screen.
 * ---------------------------------------------------------------------- */
void set_game_mode(s16 mode) {
    (void)mode;
    // No-op placeholder.
}

void set_game_mode_render_frontUI(s16 mode, void (*renderFunc)(void)) {
    (void)mode; (void)renderFunc;
    // No-op placeholder.
}