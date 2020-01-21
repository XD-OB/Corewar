.name "Torpille"
.comment "by sebc"

	xor	r4,r4,r4
debut:
	fork	%:debut2
	st	r1, :ld1
ld1:	live	%0
	fork	%:ld2
	# process qui dit live pour T1
	st	r1, :live1
	ld	%-10, r2
	ld	%1, r3
live1:	live	%4
	add	r2, r3, r2
	zjmp	%:live1b
	xor	r4, r4, r4
	zjmp	%:live1
live1b:	fork	%:ld2
	ld	%-10, r2
	xor	r4, r4, r4
	zjmp	%:live1

debut2:
	st	r1, :ld2
ld2:	live	%0
	fork	%:ld2
	# process qui dit live pour T2
	st	r1, :live2
	ld	%-10, r2
	ld	%1, r3

live2:	live	%4
	add	r2, r3, r2
	zjmp	%:live2b
	xor	r4, r4, r4
	zjmp	%:live2

live2b:	fork	%:ld2
	ld	%-10, r2
	xor	r4, r4, r4
	zjmp	%:live2

