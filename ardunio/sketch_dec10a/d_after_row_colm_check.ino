int after_row_colm_check() {
  int value = 0;
  int temp_value = 0;

  for (int yrc = 0; yrc < q; yrc++) {
    if ((temp_row[yrc] != 0) && (temp_colm[yrc] == 0)) {
      value = yrc + 1;
      break;
    }
  }

  if (value == 0) {
    for (int yrc = 0; yrc < q; yrc++) {
      if ((temp_row[yrc] != 0) ) {
        temp_value = temp_colm[yrc];
        value=yrc+1;
        break;
      }
    }

    for (int yrc = 0; yrc < q; yrc++) {
      if ((temp_row[yrc] != 0) && (temp_colm[yrc] <temp_value)) {
        temp_value = temp_colm[yrc];
        value = yrc + 1;
       
      }
    }

  }

  return value;
}
