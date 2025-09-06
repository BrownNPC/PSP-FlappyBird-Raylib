#pragma once
#include "fruit.h"
#include "scenes.h"
#include "vector2.h"

Vector2 PLAYERSTARTPOS = (Vector2){480.0 / 3.0, 150};

typedef struct {
  Fruit Player;
} SceneStart;


void SceneStart_Load(SceneStart *s) {
  s->Player = (Fruit){PLAYERSTARTPOS, NewV2(0, -10)};
}

bool SceneStart_Update(SceneStart *s) {
  // BirdDraw(s->Player);
  return false;
}


RegisteredScenes SceneStart_Unload(SceneStart *s) { return sceneStart; }
