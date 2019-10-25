#include "SCENE_sleeping.h"
#include "SCENE_awake.h"
#include "SCENE_jack.h"
#include "SCENE_sleep-awake.h"
#include "SCENE_awake-sleep.h"
#include "SCENE_jack-awake.h"
#include "SCENE_awake-jack.h"

//Sleeping
const AnimationObj anObj_Sleeping_Mouth[] = {
  {SCENE_Sleeping_Mouth,//byte array
  sizeof(SCENE_Sleeping_Mouth)/8,//count
  true};//loo
const AnimationObj anObj_Sleeping_Eyes[] = {
  {SCENE_Sleeping_Eyes,//byte array
  sizeof(SCENE_Sleeping_Eyes)/8,//count
  true}};//loop

//Awake
const AnimationObj anObj_Awake_Mouth[] = {
  {SCENE_Awake_Mouth,//byte array
  sizeof(SCENE_Awake_Mouth)/8,//count
  true};//loop

const AnimationObj anObj_Awake_Eyes[] = {
  {SCENE_Awake_Eyes,//byte array
  sizeof(SCENE_Awake_Eyes)/8,//count
  true}};//loop

//Jack
const AnimationObj anObj_Jack_Mouth[] = {
  {SCENE_Jack_Mouth,//byte array
  sizeof(SCENE_Jack_Mouth)/8,//count
  true};//loop
const AnimationObj anObj_Jack_Eyes[] = {
  {SCENE_Jack_Eyes,//byte array
  sizeof(SCENE_Jack_Eyes)/8,//count
  true}};//loop

//sleep-awake
const AnimationObj anObj_sleep-awake_Mouth[] = {
  {SCENE_sleep-awake_Mouth,//byte array
  sizeof(SCENE_sleep-awake_Mouth)/8,//count
  false};//loop
const AnimationObj anObj_sleep-awake_Eyes[] = {
  {SCENE_sleep-awake_Eyes,//byte array
  sizeof(SCENE_sleep-awake_Eyes)/8,//count
  false}};//loop

//awake-sleep
const AnimationObj anObj_awake-sleep_Mouth[] = {
  {SCENE_awake-sleep_Mouth,//byte array
  sizeof(SCENE_awake-sleep_Mouth)/8,//count
  false};//loop
const AnimationObj anObj_awake-sleep_Eyes[] = {
  {SCENE_awake-sleep_Eyes,//byte array
  sizeof(SCENE_awake-sleep_Eyes)/8,//count
  false}};//loop

//awake-jack
const AnimationObj anObj_awake-jack_Mouth[] = {
  {SCENE_awake-jack_Mouth,//byte array
  sizeof(SCENE_awake-jack_Mouth)/8,//count
  false};//loop
const AnimationObj anObj_awake-jack_Eyes[] = {
  {SCENE_awake-jack_Eyes,//byte array
  sizeof(SCENE_awake-jack_Eyes)/8,//count
  false}};//loop

//jack-awake
const AnimationObj anObj_jack-awake_Mouth[] = {
  {SCENE_jack-awake_Mouth,//byte array
  sizeof(SCENE_jack-awake_Mouth)/8,//count
  false};//loop
const AnimationObj anObj_jack-awake_Eyes[] = {
  {SCENE_jack-awake_Eyes,//byte array
  sizeof(SCENE_jack-awake_Eyes)/8,//count
  false}};//loop