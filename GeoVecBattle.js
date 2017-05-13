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

var specA = new Array(5); // spec : 0(hit point), 1(att), 2(def), 3(critical/normal), 4(probability of critical)
var specB = new Array(5);
var length = new Array(2); // length of a, b
var unitA = new Array(100);
var unitB = new Array(100);
var turn;
var damage;
var random;
var speed;
var real_speed;
var sosu;
