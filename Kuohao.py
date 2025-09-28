def bracket_check(s: str) -> bool:
    """
    检查字符串中的括号是否匹配。
    支持: (), [], {}
    
    :param s: 输入字符串（可包含任意字符）
    :return: True 表示匹配，False 表示不匹配
    """
    stack = []  # 使用列表模拟栈
    # 定义括号映射：右括号 → 对应的左括号
    mapping = {')': '(', ']': '[', '}': '{'}

    for char in s:
        # 如果是左括号，入栈
        if char in '([{':
            stack.append(char)
        
        # 如果是右括号
        elif char in ')]}':
            # 栈为空 或 栈顶不是对应的左括号 → 不匹配
            if not stack or stack[-1] != mapping[char]:
                return False
            # 匹配则出栈
            stack.pop()
        
        # 其他字符（如字母、数字）直接忽略

    # 最终栈必须为空才算完全匹配
    return len(stack) == 0


# 测试函数
def test_bracket_check():
    test_cases = [
        "()",           # True
        "()[]{}",       # True
        "([{}])",       # True
        "{[()()]}",     # True
        "((()))",       # True
        "",             # True (空字符串)
        "([]{}(()))",   # True
        "(]",           # False
        "([)]",         # False
        "(((",          # False
        ")))",          # False
        "{[}]",         # False
        "((())",        # False
        "(()))",        # False
        "[a + (b * c)]",# True
        "{x * [y + z]}",# True
        "(((",          # False
    ]

    print("开始测试括号匹配功能...\n")

    for i, expr in enumerate(test_cases, 1):
        result = bracket_check(expr)
        status = "✅ 匹配" if result else "❌ 不匹配"
        print(f"测试 {i:2d}: {expr:<15} --> {status}")


# 主程序入口
if __name__ == "__main__":
    test_bracket_check()

    # 也可以手动输入测试
    print("\n" + "="*40)
    while True:
        user_input = input("\n请输入要检查的表达式（输入 'quit' 退出）: ")
        if user_input.lower() == 'quit':
            print("程序结束，再见！")
            break
        result = bracket_check(user_input)
        print(f"结果: {'✅ 匹配' if result else '❌ 不匹配'}")