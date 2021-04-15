// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; i < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
return count;
}

int countPairs2(int *arr, int len, int value) {
  int k, count = 0;
  while (arr[len - 1] > value) {
    —len;
  }
  for (int j = len - 1; j >= 0; —j) {
    k = 0;
    while (arr[k] + arr[j] <= value) {
      if (arr[k] + arr[j] == value) {
        ++count;
      }
      ++k;
    }
  }
return count;
}

int countPairs3(int *arr, int len, int value) {
  int k, count = 0, left, right, midd;
  while (arr[len - 1] > value) {
    —len;
  }
  for (int i = 0; i < len - 1; ++i){
    k = value - arr[i];
    left = i + 1;
    right = len - 1;
    midd = (left + right) / 2;
    while (midd != left && midd != right) {
      if (k < arr[midd]) {
        right = midd - 1;
      } else {
        if (k > arr[midd]) {
          left = midd + 1;
        } else {
          ++count;
          left = 1;
          right = 1;
          while (arr[midd - left] == k) {
            ++left;
            ++count;
          }
          while (arr[midd + right] == k) {
            ++right;
            ++count;
          }
          break;
        }
      }
    }
  }
  return count;
}
