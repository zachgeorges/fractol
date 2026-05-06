# CLAUDE.md — fract'ol Project Context

This file provides context, constraints, and requirements for the **fract'ol** project from the 42 School curriculum. Use it to guide all code generation, suggestions, and review.

---

## Project Overview

**fract'ol** is a fractal exploration program written in **C**. It renders mathematical fractals in a graphical window using the **MiniLibX** library. The mandatory fractals are the **Mandelbrot set** and the **Julia set**.

The program is launched with a fractal type as a command-line argument:
```
./fractol mandelbrot
./fractol julia <real> <imaginary>
```

---

## Hard Rules (violations = 0 at evaluation)

- Written entirely in **C**
- Must comply with the **42 Norm** at all times (see Norm section below)
- **No global variables** — everything must pass through the struct
- **No unexpected exits** — no segfaults, bus errors, double frees, or memory leaks
- All heap-allocated memory must be **freed before exit**
- Must use **MiniLibX** (mlx) — the images API is mandatory, not optional
- Must use a **Makefile** with rules: `$(NAME)`, `all`, `clean`, `fclean`, `re`
- Makefile must **not relink** unnecessarily
- Bonus files must use the `_bonus.{c/h}` suffix and have a separate `bonus` Makefile rule

---

## Mandatory Features

### Rendering
- Render the **Mandelbrot** set
- Render the **Julia** set (with parameters passed via `argv`)
- Different Julia sets must be producible by changing command-line parameters
- If no argument or an invalid argument is given: **print usage and exit cleanly**
- Must use **at least a few colors** to show fractal depth — psychedelic effects encouraged
- Mouse wheel must allow **zooming in and out** (nearly infinitely)

### Graphic management
- Display rendered image in a **window**
- Window management must be **smooth** (minimizing, switching, etc.)
- **ESC key** → close window and quit cleanly
- **Clicking the window's close button (X)** → close window and quit cleanly
- MiniLibX **images** (`mlx_new_image`, `mlx_put_image_to_window`) must be used — do not draw pixel by pixel directly to the window

---

## Allowed External Functions

```
open, close, read, write, malloc, free, perror, strerror, exit
```
- All functions from the **math library** (`-lm` flag, `man 3 math`)
- All functions from the **MiniLibX** library
- `gettimeofday()`
- `ft_printf` or any equivalent **you coded**
- **libft** is authorized — place sources in a `libft/` folder with its own Makefile

---

## File & Submission Requirements

- Files to submit: `Makefile`, `*.h`, `*.c`
- A `README.md` is required at the repo root containing:
  - First line (italicized): *This project has been created as part of the 42 curriculum by \<login\>.*
  - A **Description** section (goal + overview)
  - An **Instructions** section (compilation, installation, execution)
  - A **Resources** section (references + description of how AI was used)

---

## 42 Norm Compliance

All code must pass `norminette` without errors. Key rules:

### Functions
- Maximum **25 lines** per function (excluding the opening/closing braces)
- Maximum **5 functions** per `.c` file
- Maximum **4 parameters** per function
- Functions must be separated by one blank line
- No function definition inside another function
- Do not use `static` functions — all functions must be prototyped in `fractol.h`

### Variables
- Declarations must be at the **top of the function**, before any instructions
- One variable declaration per line
- No initialization at declaration (e.g. `int i = 0;` is forbidden — declare then assign)
- **No global variables**

### Formatting
- Indent with **tabs** (not spaces)
- Maximum **80 columns** per line
- No trailing whitespace or blank lines at the end of a file
- No more than one blank line between functions
- Opening brace `{` of a function goes on its **own line**
- Opening brace `{` of control structures (`if`, `while`, etc.) goes on the **same line**

### Control flow
- No `for` loops — use `while`
- No `do...while`
- No `switch`/`case` unless explicitly allowed by the project
- No multiple assignments on one line (`a = b = 0` is forbidden)
- Ternary operators are forbidden

### Other
- No `//` comments — use `/* */` only
- Each `.c` file must start with the 42 header comment block
- No unused variables or functions
- No function calls in variable declarations

---

## Core Struct

```c
typedef struct s_fractal
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *pixel_buffer;
    int     bits_per_pixel;
    int     line_len;
    int     endian;
    char    *name;
    double  x_min;
    double  x_max;
    double  y_min;
    double  y_max;
    double  julia_r;
    double  julia_i;
    int     max_iter;
	int     color_shift;
}   t_fractal;
```

## Core Functions

### `draw_pixel` — `render.c`
The primary pixel-writing function. Writes a single colored pixel to the image buffer at coordinates `(x, y)`.

```c
void    draw_pixel(t_fractal *fractal, int x, int y, int color)
{
    int offset;

    offset = (fractal->line_len * y) + (x * (fractal->bits_per_pixel / 8));
    *((unsigned int *)(offset + fractal->pixel_buffer)) = color;
}
```

- Called by the render loop for every pixel in the window
- `color` is a single `int` formatted as `(r << 16 | g << 8 | b)`
- Do NOT use `mlx_pixel_put` — it is too slow for fractal rendering
---

## Key Mathematical Concepts

- Every pixel maps to a **complex number** `z = a + bi`
- The iteration formula for both fractals is: `z(n+1) = z(n)² + c`
  - **Mandelbrot**: `z` starts at 0, `c` = pixel's complex position
  - **Julia**: `z` starts at pixel's complex position, `c` = fixed constant from argv
- If `|z| > 2` before `max_iter` is reached → point **diverges** → color by iteration count
- If `max_iter` is reached without escape → point is **in the set** → typically black
- The `map()` function converts pixel coordinates to complex plane coordinates:

```c
double  map(double val, double in_min, double in_max,
            double out_min, double out_max)
{
    return (out_min + (val - in_min)
        * (out_max - out_min) / (in_max - in_min));
}
```

---

## Notes for Code Generation

- Do **not** suggest or generate global variables under any circumstances
- Do **not** use `for` loops — always use `while`
- Do **not** use ternary operators
- Do **not** initialize variables at declaration
- Always keep functions under 25 lines
- Always keep files under 5 functions
- When suggesting struct changes, keep all state inside `t_fractal` — pass it by pointer
- When writing color functions, return a single `int` formatted as `(r << 16 | g << 8 | b)`
- Zoom must re-render the full image (re-call the render function after updating bounds)
- The bonus part is **out of scope** — do not suggest or generate bonus features