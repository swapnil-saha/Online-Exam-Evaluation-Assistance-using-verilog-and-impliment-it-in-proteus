void led_light(int colm) {
  z = 0;
  for (int x = 0; x < s; x++)
  {
    digitalWrite(led_pins[z], bitRead (result[x][colm], 2));
    z++;
    digitalWrite(led_pins[z], bitRead (result[x][colm], 1));
    z++;
    digitalWrite(led_pins[z], bitRead (result[x][colm], 0));
    z++;


  }

  /*
    z = 0;
    for (y = 0; y < q; y++)
    {
      digitalWrite(led_pins[z], bitRead (temp_row[y], 1));
      z++;
      digitalWrite(led_pins[z], bitRead (temp_row[y], 0));
      z++;

    }

  */
  /*

      digitalWrite(led_pins[0], bitRead (index_value, 1));
      z++;
      digitalWrite(led_pins[1], bitRead (index_value, 0));
      z++;
  */

}
