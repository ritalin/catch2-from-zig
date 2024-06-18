const std = @import("std");
const run_catch2_test = @import("./root.zig").run_catch2_test;

pub fn main() !void {
    std.debug.print("begin test...\n", .{});
    run_catch2_test();
    std.debug.print("end test...\n", .{});
}

