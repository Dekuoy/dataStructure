

#include "CharStack.h"



// 函数声明
bool bracketCheck(char str[], int length, CharStack *cs);

int main(){
    CharStack cs;
    initCharStack(&cs);
    
    // 预定义测试用例
    char testCases[][100] = {
        "()",           // 匹配 - 简单一对
        "()[]{}",       // 匹配 - 多种括号
        "([{}])",       // 匹配 - 嵌套
        "{[()()]}",     // 匹配 - 复杂嵌套
        "((()))",       // 匹配 - 连续嵌套
        "",             // 匹配 - 空字符串
        "([]{}(()))",   // 匹配 - 混合复杂
        "(]",           // 不匹配 - 类型错误
        "([)]",         // 不匹配 - 顺序错误
        "(((",          // 不匹配 - 左括号多
        ")))",          // 不匹配 - 右括号多
        "{[}]",         // 不匹配 - 交错
        "((())",        // 不匹配 - 缺少右括号
        "(()))",        // 不匹配 - 多了右括号
        "[a + (b * c)]",// 匹配 - 含其他字符（会被忽略）
        "{x * [y + z]}" // 匹配 - 含字母和运算符
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    printf("开始测试括号匹配功能...\n\n");

    for (int i = 0; i < numTests; i++) {
        // 计算当前字符串长度（去掉换行符）
        int len = 0;
        while (testCases[i][len] != '\0') {
            len++;
        }

        // 初始化栈（每次测试前都要清空栈）
        initCharStack(&cs);

        // 调用检查函数
        bool result = bracketCheck(testCases[i], len, &cs);

        // 输出结果
        printf("测试 %2d: %-15s --> %s\n", 
               i + 1, 
               testCases[i], 
               result ? "✅ 匹配" : "❌ 不匹配");
        }
    return 0;
}

bool bracketCheck(char str[],
    int length,
    CharStack *cs)
{
    for(int i = 0;i<length;i++){
        if(str[i] =='('||
            str[i] =='{'||
            str[i] =='['){
            pushChar(cs,str[i]);
        }else{
            if(stackEmpty(cs)) return false;

            char topElem;
            getTop(cs,&topElem);
            if(str[i]== ')'&& topElem!='('){
                return false;
            }else{popChar(cs,&topElem);}
                if(str[i]== ']'&& topElem!='['){
                return false;
            }else{popChar(cs,&topElem);}
                if(str[i]== '}'&& topElem!='{'){
                return false;
            }else{popChar(cs,&topElem);}
        }
    }
    return stackEmpty(cs);

}

