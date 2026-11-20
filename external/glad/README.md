# GLAD (OpenGL 3.3 Core)

Vendored OpenGL function loader generated with [glad2](https://github.com/Dav1dde/glad).

## Spec

- API: `gl:core=3.3`
- Extensions: none
- Language: C
- Option: `--loader`

## Regenerate

```bash
python3 -m venv .venv-glad
.venv-glad/bin/pip install glad2
rm -rf external/glad/include external/glad/src
.venv-glad/bin/python -m glad --api gl:core=3.3 --extensions='' --out-path=external/glad c --loader
rm -rf .venv-glad
```

Keep this `README.md` when regenerating (the command above removes only `include/` and `src/`).

Do not edit `gl.h` / `gl.c` by hand.
