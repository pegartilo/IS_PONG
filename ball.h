#ifndef BALL_H
#define BALL_H


typedef enum {up_right, mid_right, down_right, up_left, mid_left, down_left} tDir;// con esto contemplamos las 6 direcciones posibles mas facil que hacer simetria.

typedef struct 
{
	int x;
	int y;
}tBallPosition;

 typedef struct 
{
	tBallPosition position;
	tDir direction;
 }tBall;

void updateBall(tBall &ball, bool collision_player, int collisionZonePlayer, bool collision_wall);//LLama primero a updateBallDirection para saber cual es su direccion actul y despues a updateBallPosition
void updateBallPosition(tBall &ball);
void updateBallDirection(tBall &ball, bool collision_player, int collisionZonePlayer, bool collision_wall);// collisionZonePlayer es 1 si es arriba 2 en el medio y 3 abajo 

#endif