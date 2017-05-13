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
var nameA;
var nameB;

nameA = '김철수'; //수정가능
nameB = '이영희'; //수정가능
speed = 5; //수정가능

length[0] = nameA.length;
length[1] = nameB.length;

//speed
if(speed == 0) { real_speed = 2000; }
else if(speed == 1) { real_speed = 1500; }
else if(speed == 2) { real_speed = 1000; }
else if(speed == 3) { real_speed = 750; }
else if(speed == 4) { real_speed = 600; }
else if(speed == 5) { real_speed = 450; }
else if(speed == 6) { real_speed = 333; }
else if(speed == 7) { real_speed = 250; }
else if(speed == 8) { real_speed = 167; }
else if(speed == 9) { real_speed = 100; }
else { real_speed = 750; }

// turn
if(unit[0][0] > unit[1][0]) { turn = 1; }
else if(unit[0][0] < unit[1][0]) { turn = 0; }

for(i = 0; unit[0][i] == unit[1][i]; i++)
{
  if(unit[0][i+1] > unit[1][i+1]) { turn = 1; }
  else if(unit[0][i+1] < unit[1][i+1]) { turn = 0; }
}
