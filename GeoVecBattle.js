function abs(x) { //절댓값 구하기
  if(x >= 0) { return x; }
  else { return -x; }
}

function prime(x) { // 333 이하의 소수 판정하기
  var a;
  var prime = 1;
  for(a = 2; (a < 18 && a < x); a++)
  {
    if(x % a == 0)
    {
      prime = 0;
      break;
    }
  }
  if(x<2){ prime = 0; }
  return prime;
}

