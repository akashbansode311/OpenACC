#!/bin/bash
#SBATCH --job-name=OpenACC
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --time=00:05:00
#SBATCH --partition=gpu
#SBATCH --gres=gpu:1
#SBATCH --output=output_%j.out
#SBATCH --error=error_%j.err
#SBATCH --reservation=dsu

ulimit -s unlimited
# Load the required modules ----
module load spack
. /home/apps/spack/share/spack/setup-env.sh

spack load nvhpc@24.3/pesayfx

nvc++ --version

cd $HOME/OpenACC

# Run the OpenACC program ----
time ./06.matrix_mult_parallel
