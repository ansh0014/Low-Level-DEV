const std=@import("std");
fn worker() void{
    std.debug.print("Worker thread running\n",.{});
std.time.sleep(90 * std.time.ns_per_s);

}
pub fn main() !void{
    var thread=try std.Thread.spawn(.{},worker,.{});
     thread.join();
}