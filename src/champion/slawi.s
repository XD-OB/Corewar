.name   "slawi"
.comment "ouff!! lhayat s3iba fi sidi moussa...o fiya sokar"

start:	sti r1, %:live1, %1
		ld %0, r5
		zjmp %:label1

live1:	live %1

label1: sti r1, %:live2, %1
		fork %15
		add r8, r8, r8
		zjmp %:live1

live2: live %2
