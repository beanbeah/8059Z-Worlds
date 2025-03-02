//copied from https://github.com/jloh02/VEX-Worlds-2019/blob/master/include/display_lib.hpp
//im lazy
#include <string>
#include <fstream>
#include "main.h"

lv_obj_t * title;
// autonNum is public static variable

/*
static lv_res_t setAuton(lv_obj_t * btn){
  uint8_t id = lv_obj_get_free_num(btn);
  autonNum = id>5?id-5:id;
  return LV_RES_OK;
}*/

using namespace std;

static const char * btnm_map[] = {"1",""};
//static const char * btnm_map[] = {"1","2",""};
static const string display_map[] = {"Blue Middle","Red Middle", "Red SAFE", "Blue SAFE"};

void updateFile(){
  //ofstream select_file ("auton_selected.txt");
  //select_file << to_string(autonNum);
  //select_file.close();
  //delay(100);
}

/**
	switch (autonNum){
		case 0: test(); break;
		case 1: blue(); break;
		case 2: red(); break;
		case 3: redSafe(); break;
		case 4: blueSafe(); break;
	}
*/

/*Called when a button is released ot long pressed*/
static lv_res_t btnm_action_red(lv_obj_t * btnm, const char *txt)
{
  if(txt == btnm_map[0]) autonNum = 2;
  //if(txt == btnm_map[1]) autonNum = 3;

  string output = "#ff0000 Auton Selected: " + display_map[autonNum-1] +"#";
  lv_label_set_recolor(title, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(title, output.c_str());
  updateFile();

  return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}

static lv_res_t btnm_action_blue(lv_obj_t * btnm, const char *txt)
{
  if(txt == btnm_map[0]) autonNum = 1;
  //if(txt == btnm_map[1]) autonNum = 4;


  string output = "#0000ff Auton Selected: " + display_map[autonNum-1] + "#";
  lv_label_set_recolor(title, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(title, output.c_str());
  updateFile();

  return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}


void initSelector(){
  int btnm_height = (LV_VER_RES-130)/ 2;

  /*Create a title label*/
  title = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_text(title, "Auton Selected: NULL");
  /*ifstream select_file ("auton_selected.txt");
  string line;
  getline(select_file,line);
  cout << line << endl;
  if(line[0] != '\0'){
    autonNum = stoi(line);
    select_file.close();
    if(autonNum == 999) lv_label_set_text(title, "Auton Selected: Skills");
    else {
      string output = "Auton Selected: " + display_map[autonNum-1];
      lv_label_set_text(title, output.c_str());
    }
  }
  else{
    lv_label_set_text(title, "Auton Selected: NULL");
  }*/

	lv_obj_align(title, NULL, LV_ALIGN_IN_TOP_MID, 0, 15);

  /*Create a new style for the button matrix back ground*/
  static lv_style_t style_bg;
  lv_style_copy(&style_bg, &lv_style_plain);
  style_bg.body.main_color = LV_COLOR_MAKE(0x30,0x30,0x30);
  style_bg.body.grad_color = LV_COLOR_MAKE(0x30,0x30,0x30);
  style_bg.line.color = LV_COLOR_TRANSP;
  style_bg.body.padding.hor = 0;
  style_bg.body.padding.ver = 0;
  style_bg.body.padding.inner = 0;

  /*Create 2 button styles*/
  static lv_style_t style_btn_rel_red;
  static lv_style_t style_btn_pr_red;
  lv_style_copy(&style_btn_rel_red, &lv_style_btn_rel);
  style_btn_rel_red.body.main_color = LV_COLOR_MAKE(0x55, 0x00, 0x00);
  style_btn_rel_red.body.grad_color = LV_COLOR_MAKE(0x55, 0x00, 0x00);
  style_btn_rel_red.body.border.color = LV_COLOR_MAKE(0xDD, 0x00, 0x00);
  style_btn_rel_red.body.border.width = 3;
  style_btn_rel_red.body.border.opa = LV_OPA_50;
  style_btn_rel_red.body.radius = 7;

  lv_style_copy(&style_btn_pr_red, &style_btn_rel_red);
  style_btn_pr_red.body.main_color = LV_COLOR_MAKE(0xDD, 0x00, 0x00);
  style_btn_pr_red.body.grad_color = LV_COLOR_MAKE(0xDD, 0x00, 0x00);
  style_btn_pr_red.text.color = LV_COLOR_WHITE;

  static lv_style_t style_btn_rel;
  static lv_style_t style_btn_pr;
  lv_style_copy(&style_btn_rel, &lv_style_btn_rel);
  style_btn_rel.body.main_color = LV_COLOR_MAKE(0x00, 0x00, 0x55);
  style_btn_rel.body.grad_color = LV_COLOR_MAKE(0x00, 0x00, 0x55);
  style_btn_rel.body.border.color = LV_COLOR_MAKE(0x00, 0x00, 0xDD);
  style_btn_rel.body.border.width = 3;
  style_btn_rel.body.border.opa = LV_OPA_50;
  style_btn_rel.body.radius = 7;

  lv_style_copy(&style_btn_pr, &style_btn_rel);
  style_btn_pr.body.main_color = LV_COLOR_MAKE(0x00, 0x00, 0xDD);
  style_btn_pr.body.grad_color = LV_COLOR_MAKE(0x00, 0x00, 0xDD);
  style_btn_pr.text.color = LV_COLOR_WHITE;

  ////////////// Red Selector //////////////
  lv_obj_t * btnmRed = lv_btnm_create(lv_scr_act(), NULL);
  lv_btnm_set_map(btnmRed, btnm_map);
  lv_btnm_set_action(btnmRed, btnm_action_red);
  lv_obj_set_size(btnmRed, LV_HOR_RES-15,  btnm_height);
  lv_btnm_set_style(btnmRed, LV_BTNM_STYLE_BG, &style_bg);
  lv_btnm_set_style(btnmRed, LV_BTNM_STYLE_BTN_REL, &style_btn_rel_red);
  lv_btnm_set_style(btnmRed, LV_BTNM_STYLE_BTN_PR, &style_btn_pr_red);
  lv_obj_align(btnmRed, title, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

  ////////////// Blue Selector //////////////
  lv_obj_t * btnmBlue = lv_btnm_create(lv_scr_act(), btnmRed);
  lv_btnm_set_action(btnmBlue, btnm_action_blue);
  //lv_btnm_set_style(btnmBlue, LV_BTNM_STYLE_BG, &style_bg);
  lv_btnm_set_style(btnmBlue, LV_BTNM_STYLE_BTN_REL, &style_btn_rel);
  lv_btnm_set_style(btnmBlue, LV_BTNM_STYLE_BTN_PR, &style_btn_pr);
  lv_obj_align(btnmBlue, btnmRed, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

}
/*
void debugLabels(){
  ADIAnalogIn cataPot(catapultPotPort);
  Motor catapult(catapultPort);

  title = lv_label_create(lv_scr_act(), NULL);
	lv_obj_align(title, NULL, LV_ALIGN_OUT_TOP_LEFT, 10, 30);

  lv_obj_t * catapultPow = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(catapultPow, title, LV_ALIGN_OUT_TOP_LEFT, 0, 60);

  while(true){
    string val = "Pot: "+to_string(cataPot.get_value());
    lv_label_set_text(title, val.c_str());

    val = "Pow: "+to_string(catapult.get_power());
    lv_label_set_text(catapultPow, val.c_str());

    delay(300);
  }
}
*/
void clearScreen(){
  lv_obj_clean(lv_scr_act());
}