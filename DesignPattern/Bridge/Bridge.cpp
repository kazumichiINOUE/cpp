/**
 * @file: Bridge.cpp
 *
 * @brief: Bridge model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <iostream>

using namespace std;

/**
 *  @brief 表示用API仮想クラス
 */
class DisplayImpl{
  public:
    virtual void RawOpen(void)=0;
    virtual void RawPrint(const string &str)=0;
    virtual void RawClose(void)=0;
  private:
};

/**
 *  @brief String型でDisplayImplを実装
 */
class StringDisplayImpl:public DisplayImpl{
  public:
    void RawOpen(void){
      PrintLine();
    }

    void RawPrint(const string &str){
      cout<<str<<endl;
    }

    void RawClose(void){
      PrintLine();
    }

  private:
    void PrintLine(void){
      cout<<"========"<<endl;
    }

};

/**
 *  @brief Display用クラス 
 */
class Display{
  public:
    Display(DisplayImpl* impl){
      impl_=impl;
    }

   /**
    *  @brief データ表示用関数
    */
    void Show(const string &str){
      Open();
      Print(str);
      Close();
    }


    void Open(void){
      impl_->RawOpen();
    }

    void Print(const string &str){
      impl_->RawPrint(str);
    }

    void Close(void){
      impl_->RawClose();
    }

  private:
    DisplayImpl* impl_;//実装用仮想クラス

};

/**
 *  @brief Displayクラスの機能拡張(MultiShow関数の追加)
 */
class CountDisplay:public Display{
  public:
    CountDisplay(DisplayImpl* _impl):Display(_impl){}

    void MultiShow(int times,const string &str){
      Open();
      for(int i=0;i<times;i++){
        Print(str);
      }
      Close();
    }
  private:
};

int main(void){
  cout<<"Bridge Pattern Sample Start!!"<<endl;

  DisplayImpl *impl=new StringDisplayImpl();
  Display display(impl);
  display.Show("HogeHoge");

  CountDisplay cdisplay(impl);
  cdisplay.MultiShow(10,"hogahoga");

  return 0;
}
