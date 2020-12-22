
const int s = 5;
const int Q = 4;
int q;
int x; // student
int y; // question
int z; // extra
int X, Y;
int index_value;
int receive[2];
int question[2];

int temp_row[Q];
int temp_colm[Q];
int result[s][Q];



int led_pins[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};




int starting_pin = 22;
int led_number = 15;

int input_starting = 40;
int starting_num = 4;

void setup() {

  for (x = 0; x <= led_number; x++)
  {
    pinMode(x + starting_pin, OUTPUT);
  }

  for (x = 0; x < starting_num; x++)
  {
    pinMode(x + input_starting , INPUT);
  }

  question[1] = digitalRead(42); //msb
  question[0] = digitalRead(43); //lsb

  if (!question[1] & !question[0])
    q = 1;
  if (!question[1] & ( question[0]))
    q = 2;

  if (question[1] & !receive[0])
    q = 3;

  if (question[1] & question[0])
    q = 4;


  colm1();

  for (Y = 1; Y < q; Y++) {
    for (X = 0; X < s; X = X + 1) {
      colm_check(Y);
      row_check(X);
      result[X][Y] = after_row_colm_check();
    }
  }




}


void loop() {



  receive[1] = digitalRead(40); //msb
  receive[0] = digitalRead(41); //lsb

  if (!receive[1] & !receive[0])
    led_light(0);
  if (!receive[1] & (receive[0]))
    led_light(1);

  if (receive[1] & !receive[0])
    led_light(2);

  if (receive[1] & receive[0])
    led_light(3);






}
