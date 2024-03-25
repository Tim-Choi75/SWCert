/*** main.cpp ***/
#define _CRT_SECURE_NO_WARNINGS
#ifndef _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#define MAX_N 100
#define null '\0'

extern void init(); 
extern std::string registerID(int id,  std::string name);
extern std::string* inout(int id); 

#define CMD_REGISTER 1
#define CMD_INOUT 2

std::string database[1000000];
std::string comute[1000000];

/**user.cpp**/
void init()
{

}

std::string registerID(int id, std::string name)
{
    
	//id번의 사번을 name 이름의 사원과 매핑하여 저장하는 함수입니다.
	//id : 회원 번호 (1 <=  id <= 9999)
	//name : 회원 이름 (String, 최대 20글자, 영문 대문자로 주어집니다)
	//등록 가능한 사번과 이름이라면, "OK"를 반환합니다.
	//이미 사용되고 있는 사번이라면, "ERROR"를 반환합니다.
	
	char message;
	
	if(database[id] == null) {
		database[id]=name;
		message = "OK";
	} else {
		message = "ERROR";
	}
	return message;
}

std::string* inout(int id)
{
	//id번의 사번으로 등록된 사원의 출퇴근 기록을 하는 함수입니다. 
	//id : 회원 번호 (1 <= id <= 9999)
	//반환해야 하는 String 배열의 의 구성은 다음과 같습니다. 
	//첫번째 값 : id번 사번에 해당하는 사원의 이름 
	//두번째 값 : 해당 사원이 [퇴근] 상태 -> [출근] 상태라면 "IN", [출근] 상태 -> [퇴근] 상태라면 "OUT"
	//등록이 되지 않은 사원이라면 아래와 같은 구성의 String 배열을 반환합니다. 
	//첫번째 값 : "ERROR"
	//두번째 값 : "ERROR"
	
	std::string* res = new std::string[2];	
    	        
    //등록되지 않은 사원이면 Error 
	if(database[id] == null) {
		res = "ERROR";
	} else {
		if(inout[id] == "OUT") {
			inout[id] == "IN";
		} else {
			inout[id] == "OUT";
		}
	}
	
	return res;
}

///////////////////////////////////////////////////////////////

static bool run()
{
    int query_num;	
    scanf("%d", &query_num);	//13

    init(); 

    std::string userAns1;
    std::string* userAns2; 
    std::string ans1;
    std::string ans2;
    std::string name;
    int id; 
    char tmp[100];
    char tmp2[100]; 
    bool ok = true;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_REGISTER)	//1
        {
            scanf("%d %s", &id, tmp);	//1000 TOM
            name = tmp; 
            userAns1 = registerID(id, name); 

            scanf("%s", tmp); 
            ans1 = tmp;

            if (ans1 != userAns1)
                ok = false;
        }
        else if (query == CMD_INOUT)
        {
            scanf("%d", &id);

            userAns2 = inout(id);

            scanf("%s %s", tmp, tmp2);

            ans1 = tmp; 
            ans2 = tmp2; 

            if (ans1 != userAns2[0] || ans2 != userAns2[1])
                ok = false;
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("./EmployComute.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);	//1 100

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
