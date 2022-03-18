#define maxHorizontalPWM 350//old value = 270
#define maxVertical_V1_V2_PWM 350
#define maxVertical_V3_PWM 230
#define CENTER_THROTTLE 1500
#define red 1
#define black -1
#define up 1
#define down -1

void move(int dir, int Speed)
{
  if (dir != prevDir)
  {
    prevDir = dir;
    if (dir == 1) //forward
    {
      /**
        _l1->red
        _l2->red
        _r1->red
        _r2->red
      */
      Speed = maxHorizontalPWM;
      int speedRed = CENTER_THROTTLE + red * Speed;
      //l1.writeMicroseconds(speedRed);
      l2.writeMicroseconds(speedRed - 50);
      //r1.writeMicroseconds(speedRed);
      r2.writeMicroseconds(speedRed);
      digitalWrite(l1_led, HIGH);
      digitalWrite(l2_led, HIGH);
      digitalWrite(r1_led, HIGH);
      digitalWrite(r2_led, HIGH);

      // uncomment when need to start micro
      micro.writeMicroseconds(speedRed);
      digitalWrite(micro_led, HIGH);
    }
    else if (dir == 2) //backward
    {
      /**
        _l1->black
        _l2->black
        _r1->black
        _r2->black
      */
      Speed = min(Speed, maxHorizontalPWM);
      int speedBlack = CENTER_THROTTLE + black * Speed;
      //l1.writeMicroseconds(speedBlack);
      l2.writeMicroseconds(speedBlack + 50);
      //r1.writepMicroseconds(speedBlack);
      r2.writeMicroseconds(speedBlack);
      digitalWrite(l1_led, HIGH);
      digitalWrite(l2_led, HIGH);
      digitalWrite(r1_led, HIGH);
      digitalWrite(r2_led, HIGH);

      // uncomment when need to start micro
      micro.writeMicroseconds(speedBlack);
      digitalWrite(micro_led, HIGH);
    }
    else if (dir == 6) //turn right
    {
      /**
        _l1->red
        _l2->black
        _r1->black
        _r2->red
      */
      Speed = maxHorizontalPWM;
      int speedRed = CENTER_THROTTLE + red * Speed;
      int speedBlack = CENTER_THROTTLE + black * Speed;
      //l1.writeMicroseconds(speedRed);
      l2.writeMicroseconds(speedBlack);
      //r1.writeMicroseconds(speedBlack);
      r2.writeMicroseconds(speedRed);
      digitalWrite(l1_led, HIGH);
      digitalWrite(l2_led, HIGH);
      digitalWrite(r1_led, HIGH);
      digitalWrite(r2_led, HIGH);
    }
    else if (dir == 5) //turn left
    {
      /**
        _l1->black
        _l2->red
        _r1->red
        _r2->black
      */
      Speed = maxHorizontalPWM;
      int speedRed = CENTER_THROTTLE + red * Speed;
      int speedBlack = CENTER_THROTTLE + black * Speed;
      //l1.writeMicroseconds(speedBlack);
      l2.writeMicroseconds(speedRed);
      //r1.writeMicroseconds(speedRed);
      r2.writeMicroseconds(speedBlack);
      digitalWrite(l1_led, HIGH);
      digitalWrite(l2_led, HIGH);
      digitalWrite(r1_led, HIGH);
      digitalWrite(r2_led, HIGH);
    }
    /*else if (dir == 4) //right
    {
      /**
        _l1->red
        _l2->red
        _r1->black
        _r2->black
      */
      /*Speed = maxHorizontalPWM;
      int speedRed = CENTER_THROTTLE + red * Speed;
      int speedBlack = CENTER_THROTTLE + black * Speed;
      //l1.writeMicroseconds(speedRed);
      l2.writeMicroseconds(speedRed);
      //r1.writeMicroseconds(speedBlack);
      r2.writeMicroseconds(speedBlack);
      digitalWrite(l1_led, HIGH);
      digitalWrite(l2_led, HIGH);
      digitalWrite(r1_led, HIGH);
      digitalWrite(r2_led, HIGH);
    }
    else if (dir == 3) //left
    {
      /**
        _l1->black
        _l2->black
        _r1->red
        _r2->red
      */
     /* Speed = maxHorizontalPWM;
      int speedRed = CENTER_THROTTLE + red * Speed;
      int speedBlack = CENTER_THROTTLE + black * Speed;
      //l1.writeMicroseconds(speedBlack);
      l2.writeMicroseconds(speedBlack);
      //r1.writeMicroseconds(speedRed);
      r2.writeMicroseconds(speedRed);
      digitalWrite(l1_led, HIGH);
      digitalWrite(l2_led, HIGH);
      digitalWrite(r1_led, HIGH);
      digitalWrite(r2_led, HIGH);
    }*/
    else if (dir == 7) //up
    {
      /**
        _v1->up
        _v2->up
      */
      Speed = maxVertical_V1_V2_PWM;
      int speedUp = CENTER_THROTTLE + up * Speed;
      v1.writeMicroseconds(speedUp);
      v2.writeMicroseconds(speedUp);
      digitalWrite(v1_led, HIGH);
      digitalWrite(v2_led, HIGH);
    }
    else if (dir == 8) //down
    {
      /**
        _v1->down
        _v2->down
      */
      Speed = maxVertical_V1_V2_PWM;
      int speedDown = CENTER_THROTTLE + down * Speed;
      v1.writeMicroseconds(speedDown);
      v2.writeMicroseconds(speedDown);
      digitalWrite(v1_led, HIGH);
      digitalWrite(v2_led, HIGH);
    }
    else if (dir == 9) //turnForwardAboutX_Axis
    {
      /**
        _v3->up
      */
      Speed = maxVertical_V3_PWM;
      int speedUp = CENTER_THROTTLE + up * Speed;
    }
    else if (dir == 10) //turnBackwardAboutX_Axis
    {
      /**
        _v3->down
      */
      Speed = maxVertical_V3_PWM;
      int speedDown = CENTER_THROTTLE + down * Speed;
    }
    else if (dir == 11) //turnRightAboutY_Axis
    {
      /**
        _v1->up
        _v2->down
      */
      Speed = maxVertical_V1_V2_PWM;
      int speedDown = CENTER_THROTTLE + down * Speed;
      int speedUp = CENTER_THROTTLE + up * Speed;
      v1.writeMicroseconds(speedUp);
      v2.writeMicroseconds(speedDown);
      digitalWrite(v1_led, HIGH);
      digitalWrite(v2_led, HIGH);
    }
    else if (dir == 12) //turnLeftAboutY_Axis
    {
      /**
        _v1->down
        _v2->up
      */
      Speed = maxVertical_V1_V2_PWM;
      int speedDown = CENTER_THROTTLE + down * Speed;
      int speedUp = CENTER_THROTTLE + up * Speed;
      v1.writeMicroseconds(speedDown);
      v2.writeMicroseconds(speedUp);
      digitalWrite(v1_led, HIGH);
      digitalWrite(v2_led, HIGH);
    }
    else
    {
      v1.writeMicroseconds(CENTER_THROTTLE);
      v2.writeMicroseconds(CENTER_THROTTLE);
      //l1.writeMicroseconds(CENTER_THROTTLE);
      l2.writeMicroseconds(CENTER_THROTTLE);
      //r1.writeMicroseconds(CENTER_THROTTLE);
      r2.writeMicroseconds(CENTER_THROTTLE);
      micro.writeMicroseconds(CENTER_THROTTLE);
      digitalWrite(l1_led, LOW);
      digitalWrite(l2_led, LOW);
      digitalWrite(r1_led, LOW);
      digitalWrite(r2_led, LOW);
      digitalWrite(v1_led, LOW);
      digitalWrite(v2_led, LOW);
      digitalWrite(micro_led, LOW);
    }
  }
}
