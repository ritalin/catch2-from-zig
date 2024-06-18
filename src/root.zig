const std = @import("std");
const testing = std.testing;

pub extern fn run_catch2_test() callconv(.C) c_int;

test "root" {
    const allocator = std.testing.allocator;

    const err = run_catch2_test();
    
    if (err > 0) {
        // ファイルからCatch2の結果を読み取る
        const file = try std.fs.cwd().openFile("output.txt", .{});
        defer file.close();

        const meta = try file.metadata();
        const data = try file.readToEndAlloc(allocator, meta.size());
        defer allocator.free(data);

        std.debug.print("Catch2 output:\n{s}\n", .{data}); 
    }

    try testing.expectEqual(0, err);
}
