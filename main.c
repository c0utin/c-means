#include <stdio.h>

#include <raylib.h>

#define MIN_X -20.0
#define MAX_X 20.0
#define MIN_Y -20.0
#define MAX_Y 20.0

Vector2 projectSampleToScreen(Vector2 sample){

  float w = GetScreenWidth();
  float h = GetScreenHeight();
  return CLITERAL(Vector2){
    .x = (sample.x - MIN_X)/(MAX_X - MIN_X)* w,
    .y = h - (sample.y - MIN_Y)/(MAX_Y - MIN_Y)* h,
  };

}

int main(void){

  InitWindow(800, 600, "c-means");
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(GetColor(0x181818AA));
    Vector2 sample = {-10, -10};
    DrawCircleV(projectSampleToScreen(sample), 5, RED);
    EndDrawing();
  }
  CloseWindow();

  return 0;
}
