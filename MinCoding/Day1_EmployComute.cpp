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
    
	//id���� ����� name �̸��� ����� �����Ͽ� �����ϴ� �Լ��Դϴ�.
	//id : ȸ�� ��ȣ (1 <=  id <= 9999)
	//name : ȸ�� �̸� (String, �ִ� 20����, ���� �빮�ڷ� �־����ϴ�)
	//��� ������ ����� �̸��̶��, "OK"�� ��ȯ�մϴ�.
	//�̹� ���ǰ� �ִ� ����̶��, "ERROR"�� ��ȯ�մϴ�.
	
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
	//id���� ������� ��ϵ� ����� ����� ����� �ϴ� �Լ��Դϴ�. 
	//id : ȸ�� ��ȣ (1 <= id <= 9999)
	//��ȯ�ؾ� �ϴ� String �迭�� �� ������ ������ �����ϴ�. 
	//ù��° �� : id�� ����� �ش��ϴ� ����� �̸� 
	//�ι�° �� : �ش� ����� [���] ���� -> [���] ���¶�� "IN", [���] ���� -> [���] ���¶�� "OUT"
	//����� ���� ���� ����̶�� �Ʒ��� ���� ������ String �迭�� ��ȯ�մϴ�. 
	//ù��° �� : "ERROR"
	//�ι�° �� : "ERROR"
	
	std::string* res = new std::string[2];	
    	        
    //��ϵ��� ���� ����̸� Error 
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
