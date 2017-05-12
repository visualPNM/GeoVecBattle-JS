#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
int abs(int x)
{
  if(x >= 0) return x;
  else return -x;
}

int prime(int x) // 소수 판정 함수
{
  int a;
  int prime = 1;
  for(a = 2; (a < 18 && a < x); a++) // 체력이 333 이하이고 18은 합성수이므로 2~17로 나누어지지 않으면 소수
  {
    if(x % a == 0)
    {
      prime = 0;
      break;
    }
  }
  if(x < 2) prime = 0;
  return prime;
}

int main()
{
  int spec[2][5] = {0}; // spec : 0(hit point), 1(att), 2(def), 3(critical/normal), 4(probability of critical)
  int length[2]; // length of a, b
  char unit[2][100];
  int turn;
  int damage;
  int random;
  int speed;
  int real_speed;
  int sosu;
  
  FILE *txt = fopen("기베엑배틀_by_수능시험_result.txt", "w");
  
  printf("[마법의 MD5 배틀 패러디! 기베엑 배틀! For C++, By 수능시험] [2017.05.12]\n");
  fprintf(txt, "[마법의 MD5 배틀 패러디! 기베엑 배틀! For C++, By 수능시험] [2017.05.12]\n");
  printf("[주의사항] 띄어쓰기 금지! 예를 들어 '소수년도의 저주'는\n'소수년도의저주'로 해 주세요!\n");
  fprintf(txt, "[주의사항] 띄어쓰기 금지! 예를 들어 '소수년도의 저주'는 '소수년도의저주'로 해 주세요!\n");
  printf("\n1번째 캐릭터 이름 입력:\n");
  scanf("%s", unit[0]);
  printf("2번째 캐릭터 이름 입력:\n");
  scanf("%s", unit[1]);
  printf("전투 속도 입력(0 : 가장느리게 ~ 9 : 가장빠르게) / 다르게 입력하면 3으로 처리\n");
  scanf("%d", &speed);
  length[0] = strlen(unit[0]);
  length[1] = strlen(unit[1]);
  
  // speed
  if(speed == 0) real_speed = 2000;
  else if(speed == 1) real_speed = 1500;
  else if(speed == 2) real_speed = 1000;
  else if(speed == 3) real_speed = 750;
  else if(speed == 4) real_speed = 600;
  else if(speed == 5) real_speed = 450;
  else if(speed == 6) real_speed = 333;
  else if(speed == 7) real_speed = 250;
  else if(speed == 8) real_speed = 167;
  else if(speed == 9) real_speed = 100;
  else real_speed = 750;
  
  // turn
  if(unit[0][0] > unit[1][0]) turn = 1;
  else if(unit[0][0] < unit[1][0]) turn = 0;
  for(int i = 0; unit[0][i] == unit[1][i]; i++)
  {
    if(unit[0][i+1] > unit[1][i+1]) turn = 1;
    else if(unit[0][i+1] < unit[1][i+1]) turn = 0;
  }
  
  // for : setting each character's spec
  for(int h = 0; h < 2; h++)
  {
    for(int i = 0; i < length[h]; i++) // character 1
    {
      if(unit[h][i] == ' ') continue;
        spec[h][0] += abs(unit[h][i]);
        spec[h][1] += 2*abs(unit[h][i]);
        spec[h][2] *= abs(unit[h][i]);
        spec[h][2] += abs(unit[h][i]) + 7;
        spec[h][3] *= abs(unit[h][i]);
        spec[h][3] += 2*abs(unit[h][i]) + 7;
        spec[h][4] += abs(unit[h][i])*abs(unit[h][i]);
        
        spec[h][0] = 100 + spec[h][0] % 234;
        spec[h][1] = 10 + spec[h][1] % 24;
        spec[h][2] = spec[h][2] % 333;
        spec[h][3] = spec[h][1] * (spec[h][3] % 3 + 3);
        spec[h][4] = 3 + spec[h][4] % 31;
      }
    }
  
  // seed for random
  srand(spec[0][0] + spec[1][0]);
  
  // spec
  printf("\n가능범위 : 체력 100~333, 공격 10~33, 방어 0~332,\n크리티컬공격력은 기본공격력의 3~5배, 크리티컬확률 3~33%%\n\n");
  fprintf(txt, "\n가능범위 : 체력 100~333, 공격 10~33, 방어 0~332,\n크리티컬공격력은 기본공격력의 3~5배, 크리티컬확률 3~33%%\n\n");
  printf("캐릭터 1 [%s] 스펙 :\n체력 %3d / 공격 %2d / 방어 %3d / 크리티컬공격력 %3d / 크리티컬확률 %2d%%\n", unit[0], spec[0][0], spec[0][1], spec[0][2], spec[0][3], spec[0][4]);
  fprintf(txt, "캐릭터 1 [%s] 스펙 :\n체력 %3d / 공격 %2d / 방어 %3d / 크리티컬공격력 %3d / 크리티컬확률 %2d%%\n", unit[0], spec[0][0], spec[0][1], spec[0][2], spec[0][3], spec[0][4]);
  printf("캐릭터 2 [%s] 스펙 :\n체력 %3d / 공격 %2d / 방어 %3d / 크리티컬공격력 %3d / 크리티컬확률 %2d%%\n", unit[1], spec[1][0], spec[1][1], spec[1][2], spec[1][3], spec[1][4]);
  fprintf(txt, "캐릭터 2 [%s] 스펙 :\n체력 %3d / 공격 %2d / 방어 %3d / 크리티컬공격력 %3d / 크리티컬확률 %2d%%\n", unit[1], spec[1][0], spec[1][1], spec[1][2], spec[1][3], spec[1][4]);
  printf("전투개시!\n");
  
  if(turn == 0)
  {
    printf("캐릭터 1 [%s] 선공!\n\n", unit[0]);
    fprintf(txt, "캐릭터 1 [%s] 선공!\n\n", unit[0]);
  }
  else
  {
    printf("캐릭터 2 [%s] 선공!\n\n", unit[1]);
    fprintf(txt, "캐릭터 2 [%s] 선공!\n\n", unit[1]);
  }
  
  while(spec[0][0] > 0 && spec[1][0] > 0)
  {
    random = rand() % 100;
    sosu = 0;
    if(turn == 0) // 캐릭터 1 공격
    {
      if(prime(spec[1][0])) sosu = 1; // 상대방 캐릭터 체력이 소수
      if(random < spec[0][4])
      {
        damage = spec[0][3] * (500 - spec[1][2]) / 500;
        printf("[%s]의 Critical Hit!!!\n", unit[0]);
        fprintf(txt, "[%s]의 Critical Hit!!!\n", unit[0]);
      }
      else damage = spec[0][1] * (500 - spec[1][2]) / 500;
      spec[1][0] -= damage * (sosu + 1);
      if(spec[1][0] < 0) spec[1][0] = 0;
      if(sosu)
      {
        printf("캐릭터 2의 체력이 소수이므로 데미지가 2배가 됩니다. 기베엑.\n");
        fprintf(txt, "캐릭터 2의 체력이 소수이므로 데미지가 2배가 됩니다. 기베엑.\n");
      }
      printf("캐릭터 1 [%s] 공격 -> 캐릭터 2 [%s]는 %d의 데미지를 받음.\n현재 체력 %s=[%3d], %s=[%3d]\n\n", unit[0], unit[1], damage*(sosu+1), unit[0], spec[0][0], unit[1], spec[1][0]);
      fprintf(txt, "캐릭터 1 [%s] 공격 -> 캐릭터 2 [%s]는 %d의 데미지를 받음.\n현재 체력 %s=[%3d], %s=[%3d]\n\n", unit[0], unit[1], damage*(sosu+1), unit[0], spec[0][0], unit[1], spec[1][0]);
      turn = 1;
    }
    else // 캐릭터 2 공격
    {
      if(prime(spec[0][0])) sosu = 1; // 상대방 캐릭터 체력이 소수
      if(random < spec[1][4])
      {
        damage = spec[1][3] * (500 - spec[0][2]) / 500;
        printf("[%s]의 Critical Hit!!!\n", unit[1]);
        fprintf(txt, "[%s]의 Critical Hit!!!\n", unit[1]);
      }
      else damage = spec[1][1] * (500 - spec[0][2]) / 500;
      spec[0][0] -= damage * (sosu + 1);
      if(spec[0][0] < 0) spec[0][0] = 0;
      if(sosu)
      {
        printf("캐릭터 1의 체력이 소수이므로 데미지가 2배가 됩니다. 기베엑.\n");
        fprintf(txt, "캐릭터 1의 체력이 소수이므로 데미지가 2배가 됩니다. 기베엑.\n");
      }
      printf("캐릭터 2 [%s] 공격 -> 캐릭터 1 [%s]는 %d의 데미지를 받음.\n현재 체력 %s=[%3d], %s=[%3d]\n\n", unit[1], unit[0], damage*(sosu+1), unit[0], spec[0][0], unit[1], spec[1][0]);
      fprintf(txt, "캐릭터 2 [%s] 공격 -> 캐릭터 1 [%s]는 %d의 데미지를 받음.\n현재 체력 %s=[%3d], %s=[%3d]\n\n", unit[1], unit[0], damage*(sosu+1), unit[0], spec[0][0], unit[1], spec[1][0]);
      turn = 0;
    }
    Sleep(real_speed);
  }
  if(spec[1][0] == 0)
  {
    printf("캐릭터 1 [%s] 승리함. 기베엑.\n", unit[0]);
    fprintf(txt, "캐릭터 1 [%s] 승리함. 기베엑.\n", unit[0]);
  }
  else if(spec[0][0] == 0)
  {
    printf("캐릭터 2 [%s] 승리함. 기베엑.\n", unit[1]);
    fprintf(txt, "캐릭터 2 [%s] 승리함. 기베엑.\n", unit[1]);
  }
  fprintf(txt, "다운로드 : 나무라이브(http://namu.live/b/wiki/134692)\n");
  fclose(txt);
  system("notepad 기베엑배틀_by_수능시험_result.txt");
  return 0;
}
