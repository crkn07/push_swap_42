/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:22:43 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/20 17:46:06 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	times_rotate_stacks(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		i = checkplace_instack(stack_b, j);
		if (i < index_in_stack(stack_a, j))
			i = index_in_stack(stack_a, j);
	}
	else if (c == 'A')
	{
		i = checkplace_instack_a(stack_a, j);
		if (i < index_in_stack(stack_b, j))
			i = index_in_stack(stack_b, j);
	}	
	return (i);
}

int	times_reverse_rotate_stacks(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (checkplace_instack(stack_b, j))
			i = ft_listsize(stack_b) - checkplace_instack(stack_b, j);
		if ((i < (ft_listsize(stack_a) - index_in_stack(stack_a, j))) && index_in_stack(stack_a, j))
			i = ft_listsize(stack_a) - index_in_stack(stack_a, j);
	}
	else if (c == 'A')
	{
		//!printf("%ld\n", stack_a->nbr);
		if (checkplace_instack_a(stack_a, j))
			i = ft_listsize(stack_a) - checkplace_instack_a(stack_a, j);
		if ((i < (ft_listsize(stack_b) - index_in_stack(stack_b, j))) && index_in_stack(stack_b, j))
			i = ft_listsize(stack_b) - index_in_stack(stack_b, j);
		//!printf("entra\n");
	}
	return (i);
}

int	times_revrota_rotb(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (index_in_stack(stack_a, j))
			i = ft_listsize(stack_a) - index_in_stack(stack_a, j);
		i = checkplace_instack(stack_b, j) + i;
	}	
	else if (c == 'A')
	{
		if (checkplace_instack_a(stack_a, j))
			i = ft_listsize(stack_a) - checkplace_instack_a(stack_a, j);
		i = index_in_stack(stack_b, j) + i;
	}
	return (i);
}

int	times_rot_a_revrotb(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (checkplace_instack(stack_b, j))
			i = ft_listsize(stack_b) - checkplace_instack(stack_b, j);
		i = index_in_stack(stack_a, j) + i;
	}
	else if (c == 'A')
	{
		if (index_in_stack(stack_b, j))
			i = ft_listsize(stack_b) - index_in_stack(stack_b, j);
		i = checkplace_instack_a(stack_a, j) + i;
	}
	return (i);
}

int	what_type_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*tmp;

	tmp = stack_a;
	i = times_reverse_rotate_stacks(stack_a, stack_b, stack_a->nbr, 'B');
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'B');
		tmp = tmp->next;
	}
	return (i);
}

int	what_type_rotate_ba(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*tmp;

	tmp = stack_b;
	i = times_reverse_rotate_stacks(stack_a, stack_b, stack_b->nbr, 'A');
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'A');
		tmp = tmp->next;
	}
	return (i);
}

//478 4 64 25 123 456 458 137 372 290 205 101 311 444 158 370 73 229 279 339 328 180 240 327 346 356 60 235 414 58 195 460 85 242 308 329 312 348 199 194 261 487 179 35 187 286 51 298 151 464 494 122 221 34 40 48 110 365 21 300 455 325 230 148 281 292 446 23 459 212 470 200 87 251 196 183 334 18 220 44 268 125 375 238 92 160 256 216 490 46 260 97 465 317 222 393 159 320 144 457 191 453 147 142 471 448 78 498 364 234 138 304 301 124 93 383 96 219 344 105 208 437 17 37 394 489 294 449 178 249 188 454 247 380 347 143 98 61 106 174 363 350 418 3 495 447 387 173 422 218 197 6 232 403 152 322 139 192 118 291 429 135 382 360 255 427 357 248 428 36 104 1 379 278 264 33 475 26 338 77 272 189 354 29 172 91 330 68 420 237 207 262 67 324 284 409 149 243 252 204 166 282 388 117 430 419 479 65 42 445 407 326 435 433 436 185 421 404 141 244 297 486 80 182 408 57 378 341 225 114 83 499 45 323 492 14 305 335 376 310 352 423 24 120 155 150 70 493 439 336 206 132 289 366 41 130 361 476 168 127 30 399 385 72 402 481 8 314 434 442 202 337 474 277 50 371 349 497 389 224 162 462 342 431 461 71 236 163 88 175 259 412 355 276 102 426 176 190 214 213 472 32 31 395 415 108 52 12 396 488 113 451 177 140 28 397 146 392 170 22 7 381 340 227 20 257 273 15 287 293 134 482 424 406 245 373 2 90 169 99 275 253 353 270 89 343 400 156 307 319 119 316 425 398 443 109 181 283 79 441 184 285 201 215 405 359 254 198 167 374 13 369 303 233 136 84 384 47 269 315 145 401 485 302 217 280 171 469 331 131 62 86 111 66 306 496 468 267 473 345 390 271 484 440 27 69 362 63 452 103 56 377 115 417 332 263 239 477 164 209 203 100 391 358 411 231 450 318 59 10 55 313 39 94 53 295 410 223 82 299 112 81 467 288 121 480 463 16 161 210 154 265 296 368 74 333 432 153 9 491 116 95 19 416 49 76 5 75 38 351 133 274 228 128 321 438 126 193 246 258 386 186 129 157 54 500 483 43 165 466 241 266 367 226 250 309 211 413 107 11 