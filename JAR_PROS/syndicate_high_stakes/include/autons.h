#include "main.h"

class Drive;
class Intake;
class Pneumatics;

extern Drive chassis;
extern Intake intake;
extern Pneumatics pneumatics;

void default_constants();

void left();
void right();
void soloAWP();
void otherpersonAWP();
void skills();