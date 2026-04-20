#!/bin/bash
#SBATCH --job-name=OpenACC
#SBATCH --partition=gpu
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --gres=gpu:1
#SBATCH --time=00:05:00
#SBATCH --output=out_%j.txt
#SBATCH --error=err_%j.txt
#SBATCH --reservation=cdac-app
ulimit -s unlimited
# ---- Load modules ----
ml spack
. /home/apps/spack/share/spack/setup-env.sh

spack load nvhpc@23.11/cc6dko5

nvc++ --version


# ---- Run ----
cd $HOME/OpenACC

time ./06.matrix_mult_parallel
