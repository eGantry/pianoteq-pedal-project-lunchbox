# pianoteq pedal project lunchbox
My second go-round at building a 4-pedal MIDI controller for PianoTeq

Solves a real-world MIDI/pedal limitation

The full hardware/software stack

PianoTeq 4-pedal support explained

Use this project as a starting point

I'm using this repo to capture how this project came together,
with a lot fewer hiccups than the first time, 8 years ago, when it was just me,
Google, Amazon, and a local, very intimidating electronics store where I felt
like an idiot every time I went to ask them a question!

Nonetheless, I was still able to find a 3-pedal sketch somewhere for an Arduino Uno 
project, which I modified for four inputs, and build out a controller with a MIDI 
hardware output soldered on, along with four pedals and jacks, all hooked up using a 
breadboard which was supposed to only be for test, but then I got lazy and just left 
it as-was.  It was a tough project, but I got there, and it worked great for eight 
years.

Fast-forward to about 3 months ago, and that controller just one day stopped working,
probably because the breadboard became oxidated over time.  Through consulting with 
the dearly-beloved ChatGPT, I discovered a much leaner process, with fewer rookie 
mistakes built in, and with no breadboard.

What I hope to share here is an even leaner version of that journey, in case some of
you would like to create a setup like my "Lunchbox" to MIDI control YOUR four piano 
pedals as PianoTeq inputs, without some of the wrong turns and things which didn't 
work along the way.

What does a lunchbox have to do with playing a virtual piano?  In my case, plenty!
I started my project with a pretty small enclosure, and ran out of space pretty 
quickly between the jacks and the Arduino, so my Uncle Charley gave me some choices,
one of which was an enclosure big enough to host a good sized bologna sandwich, with
plenty of swinging around room for wiring things up without things getting too 
cramped.

Besides that, of course, there's a lunchroom scene from "Fame", which served as an
outlet for the wild creative energy of those school-of-the-arts kids, the lunchboxes
I custom made as a kid, with tacked-on photos of Billy Preston, Billy Joel, and 
Vladimir Horowitz, and the ingerent symbolism of a lunchbox containing hand-chosen
nurishment from home, to get a young lad through a challenging schoolday.

...so the Lunchbox name is rich with symbolism, and now this Lunchbox makes my vitrual pedals
work.  Watch this space for stops along the way, which aided my journey, and which may
also help yours.

-Ron
