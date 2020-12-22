void colm_check(int colm) {


  for (int yc = 0; yc < q; yc++) {
    temp_colm[yc] = 0;
  }

  for (int yc = 0; yc < q; yc++) {
    for (int zc = 0; zc < s; zc++) {
      if (result[zc][colm] == (yc + 1))
        temp_colm[yc]++;

    }
  }


  /*
   * void led_light(){

  /*
    z=0;
    for (x=0;x<s;x++)
    {
    digitalWrite(led_pins[z],bitRead (data1[x],1));
    z++;
    digitalWrite(led_pins[z],bitRead (data1[x],0));
    z++;
    }
  */


/*
  z = 0;
  for (x = 0; x < q; x++)
  {
    digitalWrite(led_pins[z], bitRead (temp_row[x], 1));
    z++;
    digitalWrite(led_pins[z], bitRead (temp_row[x], 0));
    z++;
    
  }
*/
}
   
