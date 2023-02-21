use neon::{macro_internal::runtime::raw::FunctionCallbackInfo, prelude::*};

#[link(name = "Bannerlord.LauncherManager.Native", kind = "static")]
extern "C" {
    fn common_alloc(size: u64) -> *const std::ffi::c_void;
    fn common_dealloc(ptr: *const std::ffi::c_void);
}

fn hello(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let ptr = unsafe { common_alloc(10) };
    Ok(cx.number(ptr as u64 as f64))
}

fn bye(mut cx: FunctionContext) -> JsResult<JsUndefined> {
    let arg1 = cx.argument::<JsNumber>(0)?;
    unsafe {
        common_dealloc(arg1.value(&mut cx) as u64 as *const std::ffi::c_void);
    }
    Ok(cx.undefined())
}

#[neon::main]
fn main(mut cx: ModuleContext) -> NeonResult<()> {
    cx.export_function("hello", hello)?;
    cx.export_function("bye", bye)?;
    Ok(())
}
