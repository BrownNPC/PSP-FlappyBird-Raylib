#pragma  once
#include <raylib.h>
typedef struct {
  Vector2 Position, Velocity;
} Bird;


static inline void BirdDraw(Bird b) {
  DrawCircle(b.Position.x, b.Position.y, 20, RED);
}
