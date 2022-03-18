void servoMove(int Dir)
{
  if(Dir == 0)
  {
    if(serPos1 <= 180)
    {
      serPos1 += 20;
      servo1.write(serPos1);
    }
  }
  else if(Dir == 1)
  {
    if(serPos1 >= 0)
    {
      serPos1 -= 20;
      servo1.write(serPos1);
    }
  }
  else if(Dir == 2)
  {
    if(serPos2 >= 0)
    {
      serPos2 -= 20;
      servo2.write(serPos2);
    }
  }
  else if(Dir == 3)
  {
    if(serPos2 <= 180)
    {
      serPos2 += 20;
      servo2.write(serPos2);
    }
  }
}
