<h3>About RBD Dimmer library</h3>
<hr>

<p>The RBD Dimmer library uses hardware timer and an external interrupt. It allows multiple dimmer modules to be used on one Arduino board. The library helps to greatly simplify user code. The following functions are currently supported:</p>

<ol>
<li>dimmerLamp &mdash; this function defines the port used to control the dimmer. 
For example: dimmerLamp dimmer4(4); dimmer output DIM/PSM is assigned to port 4</li>
<li>begin &mdash; initializes ports, timer and zero-cross interrupt.
Zero-cross port is hard-coded in the library on D2
(applicable to Arduino Duemilanove, Uno, Nano, Pro mini, Leonardo, Mega)
Example: dimmer4.begin(NORMAL_MODE, ON/OFF); operational mode, ON/OFF.
<ul>
<li>Operational mode may be NORMAL_MODE or TOGGLE_MODE:
<ul>
<li> a. NORMAL_MODE &mdash; dimming value (an integer from 0% to 100%) will be defined in the sketch
Example is provided in \RBDdimmer\examples\SimpleDimmer
</li>
<li> b. TOGGLE_MODE &mdash; smooth, cyclic change of the dimming value within a defined range. This solutions uses a hardware timer only.
Example is provided in \RBDdimmer\examples\SimpleToggleDimmer</li>
</ul>
</li>
<li> ON/OFF:
<ul>
<li> a. ON &mdash; enables the hardware timer, allowing the dimmer.</li>
<li> b. OFF &mdash; disables the hardware timer, disabling the dimmer.</li>
</ul>
</li>
</ul>
</li>
<li>setPower &mdash; sets the dimming value, in% (applicable values: from 0 to 100)
Example: dimmer4.setPower(90);</li>
<li>getPower &mdash; gets the current dimming value
Example: Serial.print(dimmer4.getPower()); Result 0~100 int</li>
<li>setMode &mdash; sets and changes the operational mode (NORMAL_MODE and TOGGLE_MODE)
Example: dimmer4.setMode(NORMAL_MODE);</li>
<li>getMode &mdash; gets current operational mode
Example: Serial.print(dimmer4.getPower()); Result 0 (NORMAL_MODE) or 1 (TOGGLE_MODE)</li>
<li>setState &mdash; sets the dimming state ON/OFF
Example: dimmer4.setState(ON); delay(100); dimmer4.setState(OFF);</li>
<li>getState &mdash; displays current state of the dimmer
Example: Serial.print(dimmer4.getState()); Result 0 (OFF) or 1 (ON)</li>
<li>changeState &mdash; toggles the dimmer state
Example: dimmer4.setState(ON); delay(100); dimmer4.changeState; delay(100);</li>
<li>toggleSettings &mdash; smooth change of the dimming value (up and down) within a defined range
Example is provided in \RBDdimmer\examples\SimpleToggleDimmer</li>

</ol>
