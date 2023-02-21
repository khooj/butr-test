use std::env;

fn main() {
    let dir = env::current_dir().expect("current dir");
    println!("cargo:rustc-link-search={}", dir.to_string_lossy());
}
