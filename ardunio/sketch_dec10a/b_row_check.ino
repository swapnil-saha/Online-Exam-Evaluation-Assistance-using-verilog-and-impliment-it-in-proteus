/*
  void colm_2(){
  temp_row=row_check(2);
  //print(temp_row[0])
  //colm_check();
  //after_row_colm_check();

  }
*/
void  row_check(int row) {

  for (int yr = 0; yr < q; yr++) {
    temp_row[yr] = yr+1;
  }
  for (int yr = 0; yr < q; yr++) {
    for (int z = 0; z < q; z++) {
      if (result[row][z] == (yr + 1))
        temp_row[yr]=0;

    }
  }



}
/*
  void colm_check(int temp_data[s]) {


  for (y = 0; y < q; y++) {
    temp_colm[y] = 0;
  }

  for (y = 0; y < q; y++) {
    for (z = 0; z < x; z++) {
      if (temp_data[z] == (y + 1))
        temp_colm[y]++;

    }
  }
*/
