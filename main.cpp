#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>
#include "basic_plugin.h"
#include "basics.h"

using namespace std;
int main() {
    string cfg[10] = {"Toolbox v1.2", "Release/Debug", "Type C", "Device ID", "Program ID", "Config file", "Address", "", "", ""};
    cout << "正在连接服务器…… STEP1 Notice:连接失败则无法激活\n";
    cout
            << "正在发送验证字段…… STEP2 Notice:需要使用字段成功在服务器内查找到用户及状态，查找失败则需要注册用户或注册toolbox通行证\n";
    cout << "正在验证本机配置…… STEP3 Notice:如果没有发生错误，那么你很快就能登入。\n";
    int select;
    while (true) {
        cout << "功能菜单：1.基础--退出（已禁用） 2.基础--更多 3.二维距离计算 4.素数判断 5.阶乘 6.冰雹猜想 7.macOS、linux程序安装\n";
        cout << "8.八皇后 9.马 10.雨石";
        cout << "--->";
        cin >> select;
        cout << "<---\n";
        if (select == 1) {
            cout << "-->退出<--\n";
            cout << "!如果正常退出，将会返回【0】。!\n";
            return 0;
        } else if (select == 2) {
            cout << "请稍等，马上就要跳转到其他应用了。\n";
            cout << "开始跳转……\n";
            cout << "请注意，如果接下来5秒后，程序没有转到“设置”，请自行授权\n";
            cout << "教程：如何授权\n"
                    "请打开终端并自行转到程序所在的文件夹。\n"
                    "接下来，请输入命令【sudo chmod 755 tb-settings】\n";
            cout << "接下来，程序将自动跳转。\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            system("./tb_settings");
        } else if (select == 3) {
            cout << "工具以加载\n";
            cout << "请以以下格式输入：参数一【点1-x】参数二【点1-y】参数三【点2-x】参数四【点2-y】";
            double x1, y1, x2, y2, ans;
            cin >> x1 >> y1 >> x2 >> y2;
            ans = dis(x1, y1, x2, y2);
            cout << "已完成计算~，这是计算结果【" << ans << "】";
        } else if (select == 4) {
            cout << "工具以加载\n";
            cout << "请输入要判断的整数字：";
            int number, ans;
            cin >> number;
            ans = is_prime(number);
            cout << "\n计算结果：" << ans << endl;
        } else if (select == 5) {
            cout << "工具以加载\n";
            cout << "请输入要计算阶乘的整数字：";
            int number, ans;
            cin >> number;
            ans = factorial(number);
            cout << "\n计算结果：" << ans << endl;
        } else if (select == 6) {
            cout << "工具以加载\n";
            cout << "请输入要计算的整数字：";
            int number;
            stack<int> ans;
            cin >> number;
            ans = collatzConjecture(number);
            cout << "\n计算结果：";
            printStack(ans);
        }else if (select == 7) {
            cout << "请稍后，该程序需要扩展应用。\n";
            system("./tb_plugin_installer");
        } else {
            cout << "错误：无效的输入，请重试。如果要退出，请输入【1】。\n";
        }
    }
}


/*
 * TOOLBOX MAIN
 * V1
 */


