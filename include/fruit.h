#pragma  once
#include <raylib.h>
typedef struct {
  Vector2 Position, Velocity;
} Fruit;


static inline void BirdDraw(Fruit b) {
  DrawCircle(b.Position.x, b.Position.y, 20, RED);
}
