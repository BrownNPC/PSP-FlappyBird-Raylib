#pragma once
#include "bird.h"
#include "scenes.h"
#include "vector2.h"

Vector2 PLAYERSTARTPOS = (Vector2){480.0 / 3.0, 150};

typedef struct {
  Bird Player;
} SceneStart;


void SceneStart_Load(SceneStart *s) {
  s->Player = (Bird){PLAYERSTARTPOS, NewV2(0, -10)};
}

bool SceneStart_Update(SceneStart *s) {
  BirdDraw(s->Player);
  return false;
}


RegisteredScenes SceneStart_Unload(SceneStart *s) { return sceneStart; }
