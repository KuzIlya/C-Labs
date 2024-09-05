.code
;----------------------------------------------------------------

mystrlen proc
	; extern "C" size_t mystrlen(const char* string);
	; RCX - string
	; RAX - size_t result

	push r8
    xor rax, rax
	dec	rax

	next:
		inc rax
		mov r8b, [rcx+rax]
		cmp	r8b, 0
		jne next
		pop r8
		ret

mystrlen endp

;----------------------------------------------------------------

mycmpstr proc
	; extern "C" bool mycmpstr(const char* str1, const char* str2);
	; RCX - str1
	; RDX - str2
	; RAX - bool result

	push rdi
	push rsi
	push rcx
	push rdx

	push rcx
	mov rcx, rdx
	call mystrlen
	pop rcx
	mov rdi, rcx
	mov rsi, rdx
	mov rcx, rax
	repe cmpsb
	jz equal
	jmp not_eq

	equal:
		mov rax, 1
		jmp exit
	not_eq:
		xor rax, rax
	exit:
		pop rdx
		pop rcx
		pop rsi
		pop rdi
		ret

mycmpstr endp

;----------------------------------------------------------------

mystrstr proc
	; extern "C" char* mystrstr(const char* string, const char* substring);
	; RCX - string ptr
	; RDX - substring ptr
	; RAX - char* (nullptr) result

	call mystrlen
	mov r8, rax ; длина string

	push rcx
	mov rcx, rdx
	call mystrlen
	mov r9, rax ; длина substring
	pop rcx

	cmp r8, r9
	jl not_eq			; длина string < длина substring
	je lenstr_eq_lensub ; длина string = длина substring
	jmp str_mt_sub		; длина string > длина substring

	str_mt_sub:
		mov r10b, [rcx]
		mov r11b, [rdx]

		cmp r10b, 0
		je not_eq

		cmp r10b, r11b
		jne inc_section

		call mycmpstr
		cmp rax, 1
		je equal

		inc_section:
		inc rcx

		jmp str_mt_sub
			
	lenstr_eq_lensub:
		call mycmpstr
		cmp rax, 1
		je equal
		jmp not_eq

	not_eq:
		xor rax, rax
		ret

	equal:
		mov rax, rcx
		ret

	mystrstr endp

;----------------------------------------------------------------

end