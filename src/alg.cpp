// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len - 1; ++i) {
for (int j = i + 1; j < len; ++j) {
if (arr[i] + arr[j] == value) {
++count;
}
}
}
return count;
}

int countPairs2(int *arr, int len, int value) {
int k, count = 0;
while (arr[len - 1] > value && len > 0) {
--len;
}
if (!len) {
return 0;
}
for (int j = len - 1; j >= 0; --j) {
k = 0;
for (int k = 0; k < j; ++k) {
if (arr[k] + arr[j] == value)
++count;
}
}
return count;
}

int countPairs3(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len-1; i++) {
int left = i+1, right = len;
while (left < right) {
int midd = (left + right)/2;
if (arr[midd] == (value - arr[i])) {
while (arr[midd-1] == (value - arr[i]) && (midd > left)) {
--midd;
}
while (arr[midd] == (value - arr[i])) {
++midd;
++count;
}
break;
} else if (arr[midd] > (value - arr[i])) {
right = midd;
} else {
left = midd + 1;
}
}
}
return count;
}
