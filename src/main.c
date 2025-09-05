// Import required psp boilerplate
#include "pspinit.h"
#include "raylib.h"
#include "sceneStart.h"
#include "scenes.h"

int main(void) {
  auto ActiveScene = sceneStart;
  SceneStart SCENE_START = {};
  InitWindow(480, 270, "Flappy Bird");

  SceneStart_Load(&SCENE_START);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    switch (ActiveScene) {
    case sceneStart:
      SceneStart_Update(&SCENE_START);
      break;
    }

    EndDrawing();
  }
}
