*This project has been created as part of the 42 curriculum by zgeorges*

---

# push_swap

## Description

The `fract-ol` project involves creating graphically beautiful fractals. The goal is to provide student with an introduction to the MINILIBX graphics library, explore computer graphics optimization, and practice event handling.

---

## Instructions

### Compilation

```bash
make
make clean
make fclean
make re
```

### Usage

```bash
./fractol mandelbrot
```
or
```bash
./fractol julia <real> <imaginary>
```
### Memory Leaks Check

### Norminette checks

```bash
norminette $(find . -name "*.c" -o -name "*.h" | grep -v minilibx-linux)
```

---

## Resources

### References

- [mlx guide by Oceano](https://github.com/suspectedoceano/mlx)
- [mlx guide (video) by Oceano](https://www.youtube.com/watch?v=bYS93r6U0zg)
- [mlx documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Xlib documentation](https://tronche.com/gui/x/xlib/)
- [Geogebra mandelbrot](https://www.geogebra.org/m/mfewjrek)
- [Geogebra julia](https://www.geogebra.org/m/ea2xgWmc)

### AI usage

Claude Code was used to suggest code optimizations, notably in looped per-pixel computing, as well as provide memory leak checking commands.
It also assisted in building the Makefile.

---
## TODO


- Makefile checks 
- norm complicance

## Final Step

Retrace entire program for defense