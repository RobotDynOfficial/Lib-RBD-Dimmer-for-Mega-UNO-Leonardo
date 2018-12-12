<h3>About library</h3>
<hr>

<p>The following library is&nbsp;used for work with dimmer, it&nbsp;gives ability to&nbsp;control large ammoun of&nbsp;dimmer by&nbsp;the means of&nbsp;hardware timer and external interrupt through previously defined pin(second pin is&nbsp;used for each microcontroller)
This library can simplify user code with following functions:</p>

<ol>
<li>Function dimmerLamp&nbsp;&mdash; this function initializes the number of&nbsp;operating pin and is&nbsp;defined by&nbsp;the user
Example: dimmerLamp dimmer4(4); dimmer output DIM/PSM is&nbsp;initialized on&nbsp;the pin 4</li>
<li>Function begin port initialization, timer and external interrupt from zero-cross.
Initialization of&nbsp;zero-cross is&nbsp;set in&nbsp;the library and corresponds to&nbsp;pin D2&nbsp;on the board
(controllers Duemilanove, Uno, Nano, Pro mini, Leonardo, Mega)
Example: dimmer4.begin(NORMAL_MODE, ON/OFF); port initialization, work mode choice, ON/OFF.
<ul>
<li>Parameter&nbsp;1: dimmer working modes consist of&nbsp;two choices&nbsp;&mdash; NORMAL_MODE and TOGGLE_MODE

<ul>
<li> a. NORMAL_MODE to&nbsp;make dimmer work in&nbsp;defined value from 0&nbsp;to&nbsp;100 (%) (integer)
Example of&nbsp;this mode located in \RBDdimmer\examples\SimpleDimmer
</li>
<li>b. TOGGLE_MODE smooth change of&nbsp;dimming value up&nbsp;or&nbsp;down in&nbsp;a&nbsp;defined range. This solutions implies change of&nbsp;dimming values by&nbsp;means of&nbsp;hardware timer, without using the cycle code.
Example of&nbsp;this mode located in \RBDdimmer\examples\SimpleToggleDimmer</li>
</ul>
</li>
<li> Parameter&nbsp;2: ON/OFF.
<ul>
<li> a. ON&nbsp;&mdash; turns timer&nbsp;ON, allows to&nbsp;use dimmer.</li>
<li>b. OFF&nbsp;&mdash; turns timer parameters OFF, prevents the use of&nbsp;dimmer.</li>
</ul>
</li>
</ul>
</li>
<li> Function setPower sets dimming value from 0&nbsp;to&nbsp;100%
Example: dimmer4.setPower(90);</li>
<li>Function getPower to&nbsp;display current dimming value
Example: Serial.print(dimmer4.getPower()); Result 0~100 int</li>
<li>Function setMode sets and changes the work mode (NORMAL_MODE and TOGGLE_MODE)
dimmer4.setMode(NORMAL_MODE/TOGGLE_MODE)</li>
<li> Function getMode displays values of&nbsp;current work mode
Example: Serial.print(dimmer4.getPower()); Result&nbsp;0 (NORMAL_MODE) or&nbsp;1 (TOGGLE_MODE)</li>
<li> Function setState sets dimming state ON/OFF
Example: dimmer4.setState(ON); delay(100); dimmer4.setState(OFF);</li>
<li>Function getState displays current state of&nbsp;dimmer
Serial.print(dimmer4.getState()); Result&nbsp;0 (OFF) or&nbsp;1 (ON)</li>
<li>Function changeState changes dimmer state to&nbsp;the opposite one
Example: dimmer4.setState(ON); delay(100); dimmer4.changeState; delay(100);</li>
<li>Function toggleSettings smooth change of&nbsp;dimming value up&nbsp;or&nbsp;down in&nbsp;a&nbsp;defined range
Example located in \RBDdimmer\examples\SimpleToggleDimmer</li>

</ol>
