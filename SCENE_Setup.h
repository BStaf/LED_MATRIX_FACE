#include "SCENE_sleeping.h"
#include "SCENE_awake.h"
#include "SCENE_jack.h"
#include "SCENE_sleep_awake.h"
#include "SCENE_awake_sleep.h"
#include "SCENE_jack_awake.h"
#include "SCENE_awake_jack.h"

//sleepAwake
const AnimationObj anObj_sleepAwake_Mouth[] = {
  {SCENE_sleepAwake_Mouth,//byte array
  sizeof(SCENE_sleepAwake_Mouth)/8,//count
  false},
  {SCENE_Awake_Mouth,//byte array
  sizeof(SCENE_Awake_Mouth)/8,//count
  true}};//loop
const AnimationObj anObj_sleepAwake_Eyes[] = {
  {SCENE_sleepAwake_Eyes,//byte array
  sizeof(SCENE_sleepAwake_Eyes)/8,//count
  false},
  {SCENE_Awake_Eyes,//byte array
  sizeof(SCENE_Awake_Eyes)/8,//count
  true}};//loop

//awakeSleep
const AnimationObj anObj_awakeSleep_Mouth[] = {
  {SCENE_awakeSleep_Mouth,//byte array
  sizeof(SCENE_awakeSleep_Mouth)/8,//count
  false},
  {SCENE_Sleeping_Mouth,//byte array
  sizeof(SCENE_Sleeping_Mouth)/8,//count
  true}};//loop
const AnimationObj anObj_awakeSleep_Eyes[] = {
  {SCENE_awakeSleep_Eyes,//byte array
  sizeof(SCENE_awakeSleep_Eyes)/8,//count
  false},
  {SCENE_Sleeping_Eyes,//byte array
  sizeof(SCENE_Sleeping_Eyes)/8,//count
  true}};//loop

//awakeJack
const AnimationObj anObj_awakeJack_Mouth[] = {
  {SCENE_awakeJack_Mouth,//byte array
  sizeof(SCENE_awakeJack_Mouth)/8,//count
  false},
  {SCENE_Jack_Mouth,//byte array
  sizeof(SCENE_Jack_Mouth)/8,//count
  true}};//loop
const AnimationObj anObj_awakeJack_Eyes[] = {
  {SCENE_awakeJack_Eyes,//byte array
  sizeof(SCENE_awakeJack_Eyes)/8,//count
  false},
  {SCENE_Jack_Eyes,//byte array
  sizeof(SCENE_Jack_Eyes)/8,//count
  true}};//loop

//jackAwake
const AnimationObj anObj_jackAwake_Mouth[] = {
  {SCENE_jackAwake_Mouth,//byte array
  sizeof(SCENE_jackAwake_Mouth)/8,//count
  false},
  {SCENE_Awake_Mouth,//byte array
  sizeof(SCENE_Awake_Mouth)/8,//count
  true}};//loop
const AnimationObj anObj_jackAwake_Eyes[] = {
  {SCENE_jackAwake_Eyes,//byte array
  sizeof(SCENE_jackAwake_Eyes)/8,//count
  false},
  {SCENE_Awake_Eyes,//byte array
  sizeof(SCENE_Awake_Eyes)/8,//count
  true}};//loop
