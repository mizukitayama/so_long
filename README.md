## so_long
A graphic project from 42.

## Installation
Requirements for macOS
This project requires the following tools to be installed on macOS:

1. Xquartz

Xquartz is a crucial component for graphics display. Install it from [Xquartz official website](https://www.xquartz.org/) or use Homebrew:
```
brew install xquartz
```

2. minilibx

[minilibx](https://github.com/42Paris/minilibx-linux) is a lightweight graphics library. Install it using the following commands:

```
git clone git@github.com:42Paris/minilibx-linux.git && cd minilibx-linux
make
sudo cp libmlx.a /usr/X11/lib/
sudo cp mlx.h /usr/X11/include/
```

For detailed installation instructions, refer to these resources:

- [Installing minilibx](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)

- [minilibx setup guide](http://www.tobiusa.jp/it/dev/2021/602/)

## Compilation and Execution
To compile and run the project, follow these steps:
```
git clone git@github.com:mizukitayama/so_long.git && cd so_long
make
./so_long maps/xxx.ber
```
Replace xxx.ber with the name of a map file.
