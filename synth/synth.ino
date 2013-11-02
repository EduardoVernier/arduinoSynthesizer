// buttons
const short C_BUTTON = A0;
const short CSUS_BUTTON = A1;
const short D_BUTTON = A2;
const short DSUS_BUTTON = A3;
const short E_BUTTON = A4;
const short F_BUTTON = A5;
const short FSUS_BUTTON = A6;
const short G_BUTTON = A7;
const short GSUS_BUTTON = A8;
const short A_BUTTON = A9;
const short ASUS_BUTTON = A10;
const short B_BUTTON = A11;
const short SAW_BUTTON = 50;
const short SQUARE_BUTTON = 51;
const short SIN_BUTTON = 52;
const short NEWSIN_BUTTON = 53;

// synth A
const short ABIT0 = 10;
const short ABIT1 = 11;
const short ABIT2 = 12;
const short ABIT3 = 13;

// synth B
const short BGND = 22;
const short BBIT0 = 24;
const short BBIT1 = 26;
const short BBIT2 = 28;
const short BBIT3 = 30;
const short BBIT4 = 32;
const short BBIT5 = 34;
const short BBIT6 = 36;
const short BBIT7 = 38;
int sinValues [33] = { 0,6,12,17,22,25,28,30,31,30,28,25,22,17,12,6,0,-6,-11,-17,-21,-25,-28,-30,-30,-30,-28,-25,-22,-17,-11,-6,-0};
// VERNIER, TENTA O SENO COM ESSES VALORES AQUI !int newSinValues [33] = {15, 18, 21, 23, 26, 27, 29, 30, 31, 30, 29, 27, 26, 23, 21, 18, 15, 12, 9, 6, 4, 2, 1, 0, 0, 0, 1, 2, 4, 6, 9, 12, 15};
int newsinValues [33] = {7, 9, 10, 11, 13, 13, 14, 14, 15, 15, 14, 13, 13, 11, 10, 9, 7, 6, 5, 3, 2, 1, 0, 0, 0, 0, 1, 1, 2, 3, 4, 6, 7};


// defines that a pin is an INPUT_PULLUP using a macro
#define MODE_PULLUP(a) pinMode(a, INPUT_PULLUP)

#define SAW 0
#define SQUARE 1
#define SIN 2
#define NEWSIN 3


void setup()
{
  MODE_PULLUP(C_BUTTON);
  MODE_PULLUP(CSUS_BUTTON);
  MODE_PULLUP(D_BUTTON);
  MODE_PULLUP(DSUS_BUTTON);
  MODE_PULLUP(E_BUTTON);
  MODE_PULLUP(F_BUTTON);
  MODE_PULLUP(FSUS_BUTTON);
  MODE_PULLUP(G_BUTTON);
  MODE_PULLUP(GSUS_BUTTON);
  MODE_PULLUP(A_BUTTON);
  MODE_PULLUP(ASUS_BUTTON);
  MODE_PULLUP(B_BUTTON);
  MODE_PULLUP(SAW_BUTTON);
  MODE_PULLUP(SQUARE_BUTTON);
  MODE_PULLUP(SIN_BUTTON);
  MODE_PULLUP(NEWSIN_BUTTON);

  for (int pin = ABIT0; pin <= ABIT3; pin++)
    pinMode(pin, OUTPUT);

  for (int pin = BBIT0; pin <= BBIT7; pin = pin + 2)
    pinMode(pin, OUTPUT);

  // sets BGND as ground
  pinMode(BGND, OUTPUT);
  digitalWrite(BGND, LOW);
}



void loop()
{
  if (!digitalRead (SAW_BUTTON))
    waveKind (SAW);
  if (!digitalRead (SQUARE_BUTTON))
    waveKind (SQUARE);
  if (!digitalRead (SIN_BUTTON))
    waveKind (SIN);
  if (!digitalRead (NEWSIN_BUTTON))
    waveKind (NEWSIN);

}

void sawWave (int f)
{
  for (int i = 0; i < 31; i++)
  {
    digitalWrite(ABIT0, (i & 1));
    digitalWrite(ABIT1, (i & 2) >> 1);
    digitalWrite(ABIT2, (i & 4) >> 2);
    digitalWrite(ABIT3, (i & 8) >> 3);
    delayMicroseconds(f);
  }
}

void squareWave (int f)
{ 
    digitalWrite(ABIT0,LOW);
    digitalWrite(ABIT1,LOW);
    digitalWrite(ABIT2,LOW);
    digitalWrite(ABIT3,LOW);
    delayMicroseconds(16*f+120);
 
    digitalWrite(ABIT0,HIGH);
    digitalWrite(ABIT1,HIGH);
    digitalWrite(ABIT2,HIGH);
    digitalWrite(ABIT3,HIGH);
    delayMicroseconds(16*f+120);
}

void sinWave (int f)
{
  for (int i = 0; i < 32; i++)
  {
    digitalWrite(ABIT0, (sinValues [i] & 1));
    digitalWrite(ABIT1, (sinValues [i] & 2) >> 1);
    digitalWrite(ABIT2, (sinValues [i] & 4) >> 2);
    digitalWrite(ABIT3, (sinValues [i] & 8) >> 3);
    delayMicroseconds(f-19);
  }
}

void newsinWave (int f)
{
  for (int i = 0; i < 32; i++)
  {
    digitalWrite(ABIT0, (newsinValues [i] & 1));
    digitalWrite(ABIT1, (newsinValues [i] & 2) >> 1);
    digitalWrite(ABIT2, (newsinValues [i] & 4) >> 2);
    digitalWrite(ABIT3, (newsinValues [i] & 8) >> 3);
    delayMicroseconds(f-19);
  }
}



void waveKind (int kind)
{
  if (kind == SAW)
  {
    if (!digitalRead(C_BUTTON))
      sawWave (462);

    if (!digitalRead(CSUS_BUTTON))
      sawWave (434);

    if (!digitalRead(D_BUTTON))
      sawWave (407);

    if (!digitalRead(DSUS_BUTTON))
      sawWave (383);

    if (!digitalRead(E_BUTTON))
      sawWave (359);

    if (!digitalRead(F_BUTTON))
      sawWave (338);

    if (!digitalRead(FSUS_BUTTON))
      sawWave (318);

    if (!digitalRead(G_BUTTON))
      sawWave (298);

    if (!digitalRead(GSUS_BUTTON))
      sawWave (278);
    
    if (!digitalRead(A_BUTTON))
      sawWave (260);
    if (!digitalRead(A_BUTTON))
      sawWave (260);

    if (!digitalRead(ASUS_BUTTON))
      sawWave (247);

    if (!digitalRead(B_BUTTON))
      sawWave (230);


  }
  else
    if (kind == SQUARE)
    {
      if (!digitalRead(C_BUTTON))
        squareWave (462);

      if (!digitalRead(CSUS_BUTTON))
        squareWave (434);

      if (!digitalRead(D_BUTTON))
        squareWave (407);

      if (!digitalRead(DSUS_BUTTON))
        squareWave (383);

      if (!digitalRead(E_BUTTON))
        squareWave (359);

      if (!digitalRead(F_BUTTON))
        squareWave (338);

      if (!digitalRead(FSUS_BUTTON))
        squareWave (318);

      if (!digitalRead(G_BUTTON))
        squareWave (298);

      if (!digitalRead(GSUS_BUTTON))
        squareWave (278);
      
      if (!digitalRead(A_BUTTON))
        squareWave (260);
      if (!digitalRead(A_BUTTON))
        squareWave (260);

      if (!digitalRead(ASUS_BUTTON))
        squareWave (247);

      if (!digitalRead(B_BUTTON))
        squareWave (230);

    }
    else
      if (kind == SIN)
      {

        if (!digitalRead(C_BUTTON))
          sinWave (462);

        if (!digitalRead(CSUS_BUTTON))
          sinWave (434);

        if (!digitalRead(D_BUTTON))
          sinWave (407);

        if (!digitalRead(DSUS_BUTTON))
          sinWave (383);

        if (!digitalRead(E_BUTTON))
          sinWave (359);

        if (!digitalRead(F_BUTTON))
          sinWave (338); 

        if (!digitalRead(FSUS_BUTTON))
          sinWave (323);
        if (!digitalRead(G_BUTTON))
          sinWave (304);

        if (!digitalRead(GSUS_BUTTON))
          sinWave (278);
        
        if (!digitalRead(A_BUTTON))
          sinWave (268);
        
        if (!digitalRead(ASUS_BUTTON))
          sinWave (253);

        if (!digitalRead(B_BUTTON))
          sinWave (230);       
      }
      if (kind == NEWSIN)
      {
        if (!digitalRead(C_BUTTON))
          newsinWave (462);

        if (!digitalRead(CSUS_BUTTON))
          newsinWave (434);

        if (!digitalRead(D_BUTTON))
          newsinWave (407);

        if (!digitalRead(DSUS_BUTTON))
          newsinWave (383);

        if (!digitalRead(E_BUTTON))
          newsinWave (359);

        if (!digitalRead(F_BUTTON))
          newsinWave (338); 

        if (!digitalRead(FSUS_BUTTON))
          newsinWave (323);
        if (!digitalRead(G_BUTTON))
          newsinWave (304);

        if (!digitalRead(GSUS_BUTTON))
          newsinWave (278);
        
        if (!digitalRead(A_BUTTON))
          newsinWave (268);
        
        if (!digitalRead(ASUS_BUTTON))
          newsinWave (253);

        if (!digitalRead(B_BUTTON))
          newsinWave (230);       
      }
}
