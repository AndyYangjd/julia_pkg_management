"""
scan_pkg will update the registry, get the info of packages, and others depend the command args.
ARGS will get these args.

Usage:
    julia scan_pkg.jl --cur # get the current info of julia
    julia scan_pkg.jl --up-all  # update the pkg and ge the updated info

"""

using Pkg;

cmd_arg = ARGS[1];

if cmd_arg =="--cur"
    Pkg.status(;io=stdout);
elseif cmd_arg =="--up-all"
    Pkg.update()
    Pkg.status(;io=stdout);
    else
        println("");
    end