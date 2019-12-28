.comment "just a basic living prog"
.name "oussama dklsdjaklsjdaklsjdklasdjaskldjaklsdjaskldjaskldjaskldjasjkfhsdjkfdshjfgdshjfgdshjgdsljlgfdjkshfalfjdjksfgasldjajkfgaslfjjdfhdlfjdsjkgdl;fjdsjkfgdl;fjdshasl;fjdsjgfasl;fjdsjkfhasl;fjdsjkfhals;fhdsjkfhaslfhdsjkhfals;fhdskfhdsklghdsklghdsklhdskl"
		
l2:	sti	r1,%:live,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
